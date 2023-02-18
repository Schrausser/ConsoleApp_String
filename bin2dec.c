//----------------------------------------------------------------------------------------| BIN2DEC von Dietmar Schrausser 2009
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>

void _profil()
{
	int lauf;
	printf("\n");
	printf("BIN2DEC [b]\n");
	for(lauf=1;lauf<=17;lauf++)cprintf("\xC4"); printf("\n");
	printf("[b] ...Binaerzahl\n");
	for(lauf=1;lauf<=17;lauf++)cprintf("\xC4"); printf("\n");
	printf("BIN2DEC von Dietmar Schrausser\n");
    printf("compiliert %s @ %s\n", __DATE__, __TIME__);
	exit(1);
}
                  
int main(int argc, char *argv[])
{
	int iLauf, jLauf, index, zahl, lng;
	long int zahl_dec;
	char zahl_bin[100], zahl_bin_1[100], tmp[21];

	if(argc == 1) _profil();

	zahl= atoi(argv[1]); itoa(zahl,tmp,2);
	lng= strlen(argv[1]);	
	
	for(jLauf = 0; jLauf < lng; jLauf++) 
	{
		if (tmp[jLauf] != '1' && tmp[jLauf] !='0'){printf("\nkeine Binaerzahl .0\n"); _profil();}		 
	}
	
	if(lng > 20) {printf("\nDezimalzahl > 1.00E+06 .0\n"); _profil();}
	
	printf("\nberechne...");
	for(jLauf = 1; jLauf <= 1048575; jLauf++)
	{
		zahl_dec = jLauf;index=1;strcpy(zahl_bin," "); strcpy(zahl_bin_1," ");
		
		for(iLauf = 1; iLauf <= (sizeof( zahl_dec ) * 8); iLauf++)
		{
			zahl_dec < 0 ? strcat(zahl_bin, "1") : strcat(zahl_bin, "0") ; 
			zahl_dec <<= 1; 	
		}

		if(atoi(zahl_bin) == atoi(argv[1])) {printf ("\r%s dezimal = %i\n",argv[1], jLauf); exit(1);}
	}

	return 0;
}