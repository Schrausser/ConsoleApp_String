//---------------------------------------------------------------------------------------------------| STGERSETZ by Dietmar SCHRAUSSER 2oo8;
//                                                                                                     zur Änderung von Substrings (Einzelzeichen oder 
//																	                                   kurzer Zeichenketten) in Strings (iA.Zeile einer ASCII Datei).
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void _err_msg (); //---------------------------------------------------------------------------------> Prozedur Fehlermeldung und usage Instruktion.   
void _head(); //-------------------------------------------------------------------------------------> Prozedur für Kopfzeilen.

char dbuffer [9],tbuffer [9]; //---------------------------------------------------------------------> Buffer fuer time und date.  

char *zeichen_ptr, //--------------------------------------------------------------------------------> Zeiger auf das Zeichen[iLauf] in der urspr. Zeichenkette. 
	 _zeichenkette[100], //--------------------------------------------------------------------------> Urspr. Zeichenkette mit zu änderndem String. 
						//											                                   (wird aus Datei eingelesen).
     _zeichenkette_neu[100], //----------------------------------------------------------------------> Neue Zeichenkette mit geändertem String (wird in Datei geschrieben). 
	 *zk_zeichen, //---------------------------------------------------------------------------------> 1.Zeiger auf ausgeschnitten String (ab Zeiger zeichen_ptr) 
	             //                                                                                    mit der Länge des zu ändernden Zeichens.
	 **ptr_argv4, //---------------------------------------------------------------------------------> Zeiger auf Zeiger.
	 **ptr_argv5, //---------------------------------------------------------------------------------> Zeiger auf Zeiger.
	 *zkn_zeichen; //--------------------------------------------------------------------------------> 2.Zeiger auf ausgeschnitten String (ab Zeiger zeichen_ptr). 
                  //                                                                                   mit der Länge des zu ändernden Zeichens (sonst Kollision der Speicheradressen).

int  _zeichenkette_laenge, //------------------------------------------------------------------------> Anzahl der Zeichen in urspr. Zeichenkette.
	 zeichen_alt_laenge=1, //------------------------------------------------------------------------> Anzahl der Zeichen in zu änderndem String.
	 iLauf = 1; //-----------------------------------------------------------------------------------> Laufindex i bis Ende der urspr Zeichenkette.


FILE *instream, //-----------------------------------------------------------------------------------> Zeiger auf Eingabedatei.
	 *outstream, //----------------------------------------------------------------------------------> Zeiger auf Ausgabedatei.
	 *logstream; //----------------------------------------------------------------------------------> Zeiger auf Logdatei.

main(int argc, char *argv[])
{
	//argv[4];---------------------------------------------------------------------------------------> Zu ändernder String in urpr. Zeichenkette.
	//argv[5];---------------------------------------------------------------------------------------> Neuer String. 
	
	ptr_argv4 = argv[4] ; // ------------------------------------------------------------------------> Pointer auf Pointer (nur zur Demonstration).
	ptr_argv5 = argv[5] ; //

	if (argc != 6) //--------------------------------------------------------------------------------> Fehlerroutne:Argumente.
	{
   		printf("ERROR, check arguments!\n");
   		_err_msg(argv[0]);
	}
	
	_head(); //--------------------------------------------------------------------------------------> Kopfzeilenausgabe in Konsole.

	//-----------------------------------------------------------------------------------------------| Öffnen der Datenströme.
	logstream = fopen ("stgersetz_log.txt", "w");
	instream  = fopen ( argv[1], "r");
	outstream = fopen ( argv[2], "w");
	
	/*LOG*/ fprintf (logstream, 
					"STGERSETZ_LOG %s/%s:\ninfile:%s \noutfile:%s zeichen_alt:%s zeichen_neu:%s\n", 
					__DATE__, __TIME__,argv[1], argv[2], argv[4], argv[5]);/*LOG*/
	
	if (instream == NULL) //------------------------------------------------------------------------> Fehlerroutine:Streams.                  
	{
		printf("ERROR, check file %s!\n", argv[1]);
		_err_msg(argv[0]);
	}
	
	do //-------------------------------------------------------------------------------------------> Einlesen der urspr. Zeichenketten (Zeilen) von Datei bis EOF.
	{
		fscanf (instream, "%s", _zeichenkette);
	
		/*LOG*/ fprintf (logstream, "_zeichenkette:%s\n",_zeichenkette);/*LOG*/
		
		_zeichenkette_laenge = strlen(_zeichenkette); //--------------------------------------------> Bestimmung der Zeichenanzahl in urspr. Zeichenkette.
		zeichen_alt_laenge = strlen(ptr_argv4); //--------------------------------------------------> Bestimmung der Zeichenanzahl in zu änderndem String.
		
		/*LOG*/	fprintf (logstream, "zk_laenge:%i zeichen_alt_laenge:%i\n", 
				_zeichenkette_laenge, zeichen_alt_laenge);/*LOG*/
	
		//------------------------------------------------------------------------------------------| Änderungsschleife
		for(iLauf = 1; iLauf <= _zeichenkette_laenge; iLauf++) //                                     bis Länge der urspr. Zeichenkette. 
		{
			/*LOG*/ fprintf (logstream, "iLauf:%i\n", iLauf);/*LOG*/
		
			zeichen_ptr = &_zeichenkette[iLauf-1]; //-----------------------------------------------> Zeiger zeichen_ptr auf die Stelle iLauf-1 (nullbasiert 0,1,2...), in urspr Zeichenkette.
		
			/*LOG*/ fprintf (logstream, "zeichen_ptr:%s zeichenkette[iLauf-1]:%s\n", 
				zeichen_ptr, &_zeichenkette[iLauf-1] );/*LOG*/ 
		
			strncpy (&zk_zeichen, zeichen_ptr, zeichen_alt_laenge); //------------------------------> Kopiert einen String der Länge des zu ändernden Strings ab Stelle iLauf in zk_zeichen. 
		 
			/*LOG*/ fprintf (logstream, "zk_zeichen:%s\n", &zk_zeichen );/*LOG*/ 
		
			//--------------------------------------------------------------------------------------| Vergleich ausgeschnittener String (zk_zeichen) mit zu änderndem String (argv[3]). 
			if (strcmp (&zk_zeichen, ptr_argv4) == 0)
			{
				if ( atoi(argv[3]) == 1 ) // -------------------------------------------------------> Wenn Typ: Ändern. 
				{
					strcat(_zeichenkette_neu, ptr_argv5); //JA -------------------------------------> Anfügen von neuem String argv[4] an die neue Zeichenkette.
				}
				if ( atoi(argv[3]) == 0 ) // -------------------------------------------------------> Wenn Typ: Löschen. 
				{
					//------------------------------------------------------------------------------> Nichts an neue Zeichenkette anfügen.
				}
				if ( atoi(argv[3]) == 2 ) // -------------------------------------------------------> Wenn Typ Leerzeichen einfügen. 
				{
					strcat(_zeichenkette_neu, " "); //----------------------------------------------> Leerzeichen an neue Zeichenkette anfügen.
				}
			
				/*LOG*/ fprintf (logstream, 
								"if(TRUE):_zeichenkette_neu:%s\n", _zeichenkette_neu);/*LOG*/ 
			
				iLauf += (zeichen_alt_laenge - 1); //-----------------------------------------------> Verschiebung des Laufindex um +Stringlänge des alten Zeichens - 1 
			                                       //                                                 (Verschiebung um +1 übernimmt 'for' selbst).		
			}
			else
			{
				strncpy (&zkn_zeichen, zeichen_ptr, 1); //SONST ------------------------------------> Kopiert einen String der Länge 1 (Position iLauf in zk_zeichen).  
			 
				/*LOG*/ fprintf (logstream, "zkn_zeichen:%s\n", &zkn_zeichen );/*LOG*/ 
			
				strcat(_zeichenkette_neu, &zkn_zeichen); //-----------------------------------------> Anfügen von urspr. Zeichen an die neue Zeichenkette.
			
				/*LOG*/ fprintf (logstream, "else:_zeichenkette_neu:%s\n", _zeichenkette_neu);/*LOG*/ 
			}
		}
	
		fprintf (outstream, "%s\n", _zeichenkette_neu); //------------------------------------------> Ausgabe der neuen Zeichenkette in Ausgabedatei.
	
		strcpy (_zeichenkette_neu, ""); //----------------------------------------------------------> Löschen von zeichenkette_neu.
	
	}while (feof (instream) == 0);
	
	/*LOG*/ fprintf (logstream, "END\n----\n");/*LOG*/ 
	
	//----------------------------------------------------------------------------------------------> Schliessung der Datenströme.
	fclose (instream);
	fclose (logstream);
	fclose (outstream);

	return 0;
}

//--------------------------------------------------------------------------------------------------| Usage Instruktion                     
void _err_msg()
{
	printf("---------------------------------------------------------\n");
	printf("Usage: STGERSETZ [input] [output] [typ] [alt] [neu]\n ");
	printf("[input] .... Eingabe Datei\n");
	printf(" [output] ... Ausgabe Datei\n");
	printf(" [typ] ...... (0):loeschen\n              (1):aendern\n              (2):ein Leerzeichen einfuegen\n");
	printf(" [alt] ...... zu aendernde Zeichenkette in Eingabe Datei\n");
	printf(" [neu] ...... aendern in.. Zeichenkette \n");
	printf("---------------------------------------------------------\n");
	printf("STGERSETZ by Dietmar Schrausser\n");
        printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(EXIT_FAILURE);
}	

//--------------------------------------------------------------------------------------------------| Titelzeile                 
void _head(void) 
{
	printf("\nSTGERSETZby Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing STGERSETZ:"); 
}

//--------------------------------------------------------------------------------------------------| ENDE  
