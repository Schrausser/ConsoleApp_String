//---------------------------------------------------------------------------| ABCD by Dietmar SCHRAUSSER 2010               

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _profil(); 
void _kopf();                      

int arg_len, arg2_len, iLauf, sw=0;
char dbuffer[9],tbuffer[9], datei_in_string1[50], datei_in_string2[50];  

main(int argc, char *argv[])   
{   
	FILE *inStream, *outStream;                                 
      
	if (argc != 6) {printf("> check arguments\n");_profil();	}
   	          
	inStream = fopen( argv[1], "rb" );
	outStream = fopen( argv[2], "wb" );                                                                                  
   
	if (inStream == 0) { 	printf("> check file %s\n", argv[1]); _profil(argv[0]);}          

    arg2_len = strlen(argv[4]);

	_kopf();

	inStream = fopen( argv[1], "rb" );

                         arg_len = strlen(argv[3]);
	for(iLauf=1; iLauf<= arg_len; iLauf++) datei_in_string1[iLauf] = fgetc(inStream); //die ersten n=String_alt_länge zeichen in vektor einlesen
	
	while(1)
	{	
		sw=0; // schalterrücksetzung //

		for(iLauf=1; iLauf<= arg_len; iLauf++) if(datei_in_string1[iLauf] == argv[3][iLauf-1]) sw+=1; //zeichenvergleich, schalter sw setzung

		if(sw == arg_len) //alle zeichen übereinstimmend
		{
			if(argv[5][0]=='0')fprintf(outStream,"%s", argv[4]); //String_neu schreiben
			if(argv[5][0]=='1')fprintf(outStream,"");            //Nichts schreiben
			if(argv[5][0]=='2')fprintf(outStream," ");           //Leerzeichen schreiben
			
			for(iLauf=1; iLauf<= arg_len;  iLauf++) datei_in_string1[iLauf] = fgetc(inStream); //datei lese position um String_alt länge weiter
		}
		
		if(sw != arg_len) //kein oder nicht alle zeichen übereinstimmend
		{
			fputc (datei_in_string1[1], outStream); //erstes zeichen in output datei scheiben
			
			for(iLauf=1; iLauf< arg_len; iLauf++) datei_in_string2[iLauf] = datei_in_string1[iLauf+1]; //vektor verschiebung um 1 zeichen (tmp vektor)

			datei_in_string2[arg_len] = fgetc(inStream); //neues zeichen in letztes vektorfeld einlesen

			for(iLauf=1; iLauf<= arg_len; iLauf++) datei_in_string1[iLauf] = datei_in_string2[iLauf]; //tmp vektor in vektor schreiben
		}
		 
		if (feof (inStream) != 0 ) break;								
	}
	
	for(iLauf=1; iLauf< arg_len; iLauf++) fputc (datei_in_string1[iLauf], outStream); // restvektor in outputdatei schreiben
 
	fclose( inStream  );
	fclose( outStream );

	return 0;
}
           
void _profil()
{
	printf("-------------------------------------------------------\n");
	printf("Usage: ABCD [input] [output] [ab] [cd] [sw]\n");
	printf("[input] ... Eingabe Datei\n");
	printf("[output] .. Ausgabe Datei\n");
	printf("[ab] ...... String alt\n");
	printf("[cd] ...... String neu\n");
	printf("[sw] ...... (0):aendern (1):loeschen (2):zu Leerzeichen\n");
	printf("-------------------------------------------------------\n");
	printf("ABCD by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	
     
void _kopf() 
{
	printf("\nABCD by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing ABCD:\n"); 
}                                           
