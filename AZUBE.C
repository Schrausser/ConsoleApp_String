//---------------------------------------------------------------------------| AZUBE by Dietmar SCHRAUSSER 2oo8               

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _err_msg (); //---------------------------------------------------------> prozedur fehlermeldung und usage instruktion   
void _head(void); //---------------------------------------------------------> prozedur für kopfzeilen                        

char dbuffer [9],tbuffer [9], datei_in_zeichen;  //--------------------------> buffer fuer time und date, variable f. dateizeichenm
main(int argc, char *argv[]) //----------------------------------------------> main übernimmt n argumente im vektor argv     
{   
	FILE *inStream, *outStream; //---------------------------------------> streams                                        
      
	if (argc != 5) //----------------------------------------------------> was wenn keine oder zuwenig, zuviel argumente? 
	{
   		printf("ERROR, check arguments!\n");
   		_err_msg(argv[0]);
	}
   
	//--------------------------------------------------------------------| def von input und outputdatei:                 
	inStream = fopen( argv[1], "r" );
	outStream = fopen( argv[2], "w" );                                                                                  
   
	if (inStream == NULL) //----------------------------------------------> was wenn keine inputdatei                      
	{
		printf("ERROR, check file %s!\n", argv[1]);
		_err_msg(argv[0]);
	}
  
	_head();
   
	while(1)
	{
		datei_in_zeichen = fgetc(inStream);//-------------------------> einlesen eines zeichens von der inputdatei 
		if (feof (inStream) != 0 ) break;//---------------------------> ende wenn eof
		if (datei_in_zeichen == argv[3][0])//-------------------------> vergleich mit zu änderndem zeichen (char[0] von string pointer argv[3])
		{									
			fputc (argv[4][0], outStream);//----------------------> ausgabe von geändertem zeichen (char[0] von string pointer argv[4])	
		} 
		else 								
		{  
			fputc (datei_in_zeichen, outStream);//----------------> sonst ausgabe von ursprünglichem zeichen	
		}
	
	}	
 
	fclose( inStream  );
	fclose( outStream );

	return 0;
}

//-----------------------------------------------------------------------------| allgemeine fehlerroutine                       
void _err_msg()
{
	printf("--------------------------------------\n");
	printf("Usage: AZUBE [input] [output] [a] [b] \n ");
	printf("[input] ... Eingabe Datei \n");
	printf(" [output] .. Ausgabe Datei \n");
	printf(" [a] ...... Zeichen\n");
	printf(" [b] ...... aendern\n");
	printf("--------------------------------------\n");
	printf("AZUBE by Dietmar Schrausser\n");
        printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(EXIT_FAILURE);
}	

//-----------------------------------------------------------------------------| titelzeile bildschirmausgabe                   
void _head(void) 
{
	printf("\nAZUBE by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing AZUBE:"); 
}

//---------------------------------------------------------------------------| ENDE                                           