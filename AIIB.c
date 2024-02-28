//---------------------------------------------------------------------------| AIIB by Dietmar SCHRAUSSER 2009             

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SCHRAUSSER_CODES.h"

void _profil ();    
void _head();                    

FILE *inStream, *outStream;

int index=1, dez_1, z1, f_len, mode_, form_; 
char name[30], zei_[10], code[20], z_0[1], dmy[5], LF;

main(int argc, char *argv[])     
{    
	if (argc != 2){ printf("\ncheck arguments!\n");_profil();}
	                                                                                             
   	inStream  = fopen( argv[1], "r" );if (inStream == 0) { printf("\ncheck file %s!\n", argv[1]); _profil();}   
	
	fscanf(inStream,"%s%i%i%i\n", name, &mode_, &form_, &f_len);
	
	if(mode_ < 1 || mode_ > 4 && mode_ != 6){ printf("\ncheck *.bii fileformat!\n");_profil();}
	
	_head();
	
	outStream = fopen( name, "wb" );
	
	if(mode_ ==1) strcpy(code, "SCHRAUSSER CODE cd01"); 
	if(mode_ ==2) strcpy(code, "SCHRAUSSER CODE cd02");
	if(mode_ ==3) strcpy(code, "SCHRAUSSER CODE cd03");
	if(mode_ ==4) strcpy(code, "SCHRAUSSER CODE cd04");
	if(mode_ ==6) strcpy(code, "Decimal"); 
	
	do
	{
		if(index>1)        fputc(dez_1,outStream);    //um 1 zeichen versetzte ausgabe
						// 	fprintf(outStream,"%i\n",dez_1); // zur zeichenvergleichsprüfung
		
		if(mode_==1 || mode_==3) //cd01, cd03
		{						
								              zei_1=fgetc(inStream); 
								              zei_2=fgetc(inStream);
			       if(mode_==3)               zei_3=fgetc(inStream);
				   if(form_==1)                  LF=fgetc(inStream);
			       if(mode_==1) FnCodeAB_cd01(     ); 
			       if(mode_==3) FnCodeAB_cd03(     );			 
							       dez_1=     dez_;
		} 


		if(mode_==2 || mode_==4) //cd02, cd04
		{						
								              zei_1=fgetc(inStream);     sprintf(z_0, "%c", zei_1 );   
											                         z1=    atoi(z_0); 
				   if((mode_== 2      &&
					  (z1>=1 && z1<=8)) ||
					  (mode_== 4      &&
			          (z1>=1 && z1<=2))   )   zei_2=fgetc(inStream);
				   if(form_==1)                  LF=fgetc(inStream);
			       if(mode_==2) FnCodeAB_cd02(                       z1);      	        
				   if(mode_==4) FnCodeAB_cd04(                       z1);	
							       dez_1=     dez_;
		}                

		if(mode_==6) //dezimal
		{  
			            fscanf(inStream,"%s", zei_);
						           dez_1=atoi(zei_);
		}

		printf("\rdecoding AIIB: %s c(%i) ", code, f_len-index); 
		index++;

	}while (feof (inStream) == 0); 

	printf("\n");
 
	fclose( inStream  );fclose( outStream );
	return 0;
}
                 
void _profil()
{
	printf("-----------------------------------------\n");
	printf("Usage: AIIB [input]\n");
	printf("[input] .... SCHRAUSSER CODE file (*.bii)\n");
	printf("-----------------------------------------\n");
	printf("AIIB by Dietmar Schrausser\n");
    printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	exit(0);
}	

void _head() 
{
	printf("\nAIIB by Dietmar Schrausser\n");
	printf("compiled on %s @ %s\n", __DATE__, __TIME__);
	printf("decoding AIIB:"); 
}

                                          
