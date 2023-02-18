//----------------------------------------------------------------------------------------| DEC2BIN von Dietmar Schrausser 2009
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>

void _profil()
{
	int lauf;
	printf("\n");
	printf("DEC2BIN [d]\n");
	for(lauf=1;lauf<=17;lauf++)cprintf("\xC4"); printf("\n");
	printf("[d] ..Dezimalzahl\n");
	for(lauf=1;lauf<=17;lauf++)cprintf("\xC4"); printf("\n");
	printf("DEC2BIN von Dietmar Schrausser\n");
    printf("compiliert %s @ %s\n", __DATE__, __TIME__);
	exit(1);
}

int main(int argc, char *argv[])
{
	int iLauf,index=1, lng;
	long int zahl_dec;
	char zahl_bin[200], zahl_bin_1[200], tmp[1];

	if(argc == 1) _profil();
	lng=strlen(argv[1]);
	//if(lng > 10) {printf("\nDezimalzahl > 1.00E+10 .0\n"); _profil();}

	zahl_dec = atoi(argv[1]);
	strcpy(zahl_bin," "); strcpy(zahl_bin_1," ");
	
	for(iLauf = 1; iLauf <= (sizeof( zahl_dec ) * 8); iLauf++)
	{
		zahl_dec < 0 ? strcat(zahl_bin, "1") : strcat(zahl_bin, "0") ;
		zahl_dec <<= 1; // left shift
	}
	
	//printf ("\n%s binaer = %s\n",argv[1], zahl_bin);

	lng=strlen(zahl_bin); while (zahl_bin[index]!='1')index++;

	for(iLauf = index; iLauf <= lng; iLauf++) {sprintf(tmp,"%c", zahl_bin[iLauf]); strcat(zahl_bin_1,tmp);}

	printf ("\n%s binaer = %s\n",argv[1], zahl_bin_1);
	//printf ("%s oktal = %o\n",argv[1], atoi(argv[1]));
	//printf ("%s hexadezimal = %X\n",argv[1], atoi(argv[1]));

	return 0;
}