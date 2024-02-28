//---------------------------------------------------------------------------| BIIA by Dietmar SCHRAUSSER 2009             

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SCHRAUSSER_CODES.h"

void _profil();   
void _head();               

int index = 1, f_len=0;
char c_1, c_2, code[20];

main(int argc, char *argv[])       
{   
	FILE *inStream, *outStream;                                        
      
	if (argc != 5) {	printf("\ncheck arguments!\n");_profil();}
	if(atoi(argv[3])<1 || atoi(argv[3])>8) {	printf("\ncheck mode argument!\n");_profil();}
	if(atoi(argv[4])<1 || atoi(argv[4])>2) {	printf("\ncheck form argument!\n");_profil();}
	
	inStream = fopen( argv[1], "rb" ); if (inStream == NULL) {printf("\ncheck file %s!\n", argv[1]); _profil();	} 
	outStream = fopen( argv[2], "w" );                                                                                  
   
   if(atoi(argv[3])==1) strcpy(code, "SCHRAUSSER CODE cd01"); 
   if(atoi(argv[3])==2) strcpy(code, "SCHRAUSSER CODE cd02"); 
   if(atoi(argv[3])==3) strcpy(code, "SCHRAUSSER CODE cd03"); 
   if(atoi(argv[3])==4) strcpy(code, "SCHRAUSSER CODE cd04");
   if(atoi(argv[3])==5) strcpy(code, "Hexadecimal");
   if(atoi(argv[3])==6) strcpy(code, "Decimal");
   if(atoi(argv[3])==7) strcpy(code, "Octal");
   if(atoi(argv[3])==8) strcpy(code, "ASCII");

	_head();
    
	do{fgetc(inStream);f_len++;}while (feof(inStream)== 0); fclose(inStream ); inStream = fopen(argv[1],"rb");                                  
	
	fprintf (outStream,"%s %i %i %i\n", argv[1], atoi(argv[3]), atoi(argv[4]), f_len);
	
	do
	{
												                                c_1 = fgetc(inStream);
		if(atoi(argv[3])<=4) //codiert
		{ 
									                    sprintf(zei,"%d", c_2); 
			if(atoi(argv[3])==1)                  FnCodeBA_cd01(   );
			if(atoi(argv[3])==2)                  FnCodeBA_cd02(   );  
			if(atoi(argv[3])==3)                  FnCodeBA_cd03(   );
			if(atoi(argv[3])==4)                  FnCodeBA_cd04(   );
		}
		if(atoi(argv[3])==5)                            sprintf(zei,"%X", c_2); //hex
		if(atoi(argv[3])==6)                            sprintf(zei,"%d", c_2); //dec
		if(atoi(argv[3])==7)                            sprintf(zei,"%o", c_2); //oct
		if(atoi(argv[3])==8)                            sprintf(zei,"%c", c_2); //ascii

		if (index > 1)  // um 1 zeichen versetzte ausgabe in outstream (löscht anhängsel am ende der datei)
		{
			if(atoi(argv[4])==1)     fprintf (outStream,"%s\n", zei); //1-spaltig
			if(atoi(argv[4])==2)								      //1-zeilig
			{
				if(atoi(argv[3])<=4) {fprintf (outStream,"%s",  zei); } //ohne leerzeichen
				else                 {fprintf (outStream,"%s ", zei); } //mit  leerzeichen
			}
		}													
																		  c_2 = c_1;		
		printf("\rencoding BIIA: %s c(%i)", code, index); 
		index++;

	}while (feof (inStream) == 0); 	
	
	printf("\n"); 
 
	fclose( inStream  );fclose( outStream );return 0;
}

                 
void _profil()
{
	printf("-------------------------------------------------\n");
	printf("Usage: BIIA [input] [output] [mode] [form]\n");
	printf("[input] .... Input File\n");
	printf("[output] ... Output File ASCII *.bii\n");
	printf("[mode] ..... (1):cd01 (2):cd02 (3):cd03 (4):cd04 \n");
	printf("             (5):HEX  (6):DEC  (7):OCT  (8):ASCII\n");
	printf("[form] ..... (1):1-column (2):1-line\n");
	printf("-------------------------------------------------\n");
	printf("BIIA by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	

                 
void _head() 
{
	printf("\nBIIA by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("encoding BIIA:"); 
}

                                            
