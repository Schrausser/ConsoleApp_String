//---------------------------------------------------------------------------| AB_L by Dietmar SCHRAUSSER 2010               

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void _profil(); 
void _kopf();                      

int n_=0, iLauf;
char dbuffer[9],tbuffer[9], datei_in_string[200], out_string[200], c_;  

main(int argc, char *argv[])   
{   
	FILE *inStream, *tmpStream, *outStream;                                 
      
	if (argc != 7) {printf("\n> check arguments\n");_profil();	}
   	          
	inStream = fopen( argv[1], "rb" );
	outStream = fopen( argv[2], "wb" ); 
	   
	if (inStream == 0) { 	printf("\n> check file %s\n", argv[1]); _profil(argv[0]);}          
	
	_kopf();
	
    do { if(fgetc(inStream)=='\n') n_++;} while (feof (inStream) == 0);   fclose( inStream  );

	inStream = fopen( argv[1], "rb" );
	tmpStream = fopen( "~tmp", "w" );
	
	do 
	{ 
		            c_=fgetc(inStream);
			
		if(atoi(argv[6]) != 0 && c_=='\n') fprintf(tmpStream, " %s\n",argv[5] ); 
		else              fputc( c_, tmpStream); 

	} while (feof (inStream) == 0);   
	
	fclose( tmpStream );

	tmpStream = fopen( "~tmp", "rb" );
	
	for(iLauf=1;iLauf <= n_; iLauf++) 
	{ 
		fgets(datei_in_string, 200, tmpStream);
										
		if(atoi(argv[4]) != 0 ){ strcpy(out_string,argv[3]); strcat(out_string," "); }
		if(atoi(argv[4]) == 0 )  strcpy(out_string,"");              
		                 
		                         strcat(out_string,datei_in_string);								
													
	    fprintf(outStream,"%s",out_string);								
	}
 
	fclose( outStream );
	fclose( tmpStream );

	unlink("~tmp");
	
	return 0;
}
         
void _profil()
{
	printf("----------------------------------------------\n");
	printf("Usage: AB_L [input] [output] [a] [sw] [z] [sw]\n ");
	printf("[input] ... Eingabe Datei \n");
	printf(" [output] .. Ausgabe Datei \n");
	printf(" [a] ...... String vor Zeile\n");
	printf(" [sw] ......(0):nicht einfuegen \n");
	printf(" [z] ...... String nach Zeile\n");
	printf(" [sw] ......(0):nicht einfuegen\n");
	printf("----------------------------------------------\n");
	printf("AB_L by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	

void _kopf() 
{
	printf("\nAB_L by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("computing AB_L:\n"); 
}                                           
