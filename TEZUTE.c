//---------------------------------------------------------------------------| TEZUTE by Dietmar SCHRAUSSER 2oo8               

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _err_msg (); //---------------------------------------------------------> prozedur fehlermeldung und usage instruktion   
void _head(void); //---------------------------------------------------------> prozedur für kopfzeilen                        

char dbuffer [9],tbuffer [9], datei_in_string[30];  //-----------------------> buffer fuer time und date, variable f. dateizeichenm
main(int argc, char *argv[]) //----------------------------------------------> main übernimmt n argumente im vektor argv     
{   
	FILE *inStream, *outStream; //---------------------------------------> streams                                        
      
	if (argc != 5) //----------------------------------------------------> was wenn keine oder zuwenig, zuviel argumente? 
	{
   		printf("ERROR, check arguments!\n");
   		_err_msg(argv[0]);
	}
   
	//-------------------------------------------------------------------| def von input und outputdatei:                 
	inStream = fopen( argv[1], "r" );
	outStream = fopen( argv[2], "w" );                                                                                  
   
	if (inStream == NULL) //---------------------------------------------> was wenn keine inputdatei                      
	{
		printf("ERROR, check file %s!\n", argv[1]);
		_err_msg(argv[0]);
	}
  
	_head();
   
	do
	{
	
	fscanf (inStream,"%s", datei_in_string);
	
	if (strcmp(datei_in_string, argv[3]) == 0)	//-------------------> vergleich mit zu änderndem string 
		{									
			fprintf (outStream,"%s\n", argv[4]);//---------------> ausgabe von geändertem string (string pointer argv[4])	
		} 
		else 								
		{  
			fprintf (outStream,"%s\n", datei_in_string);//-------> sonst ausgabe von ursprünglichem zeichen	
		}
	

	}while (feof (inStream) == 0); //------------------------------------> do solange nicht end of file	
 
	fclose( inStream  );
	fclose( outStream );

	return 0;
}

//---------------------------------------------------------------------------| allgemeine fehlerroutine                       
void _err_msg()
{
	printf("--------------------------------------\n");
	printf("Usage: TEZUTE [input] [output] [a] [b] \n ");
	printf("[input] ... Eingabe Datei \n");
	printf(" [output] .. Ausgabe Datei \n");
	printf(" [a] ...... String\n");
	printf(" [b] ...... aendern\n");
	printf("--------------------------------------\n");
	printf("TEZUTE by Dietmar Schrausser\n");
        printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(EXIT_FAILURE);
}	

//---------------------------------------------------------------------------| titelzeile bildschirmausgabe                   
void _head(void) 
{
	printf("\nTEZUTE by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing TEZUTE:"); 
}

//---------------------------------------------------------------------------| ENDE                                           
