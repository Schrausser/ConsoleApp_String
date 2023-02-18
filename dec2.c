//----------------------------------------------------------------------------------------| DEC2 von Dietmar Schrausser 2009
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
	printf("DEC2 [d]\n");
	for(lauf=1;lauf<=17;lauf++)cprintf("\xC4"); printf("\n");
	printf("[d] ..Dezimalzahl\n");
	for(lauf=1;lauf<=17;lauf++)cprintf("\xC4"); printf("\n");
	printf("DEC2 von Dietmar Schrausser\n");
    printf("compiliert %s @ %s\n", __DATE__, __TIME__);
	exit(1);
}

int main(int argc, char *argv[])
{
	if(argc == 1) _profil();

	printf ("\n%s exponential = %.3e\n",argv[1], atof(argv[1]));
	printf ("%s oktal = %o\n",argv[1], atoi(argv[1]));
	printf ("%s hexadezimal = %X\n",argv[1], atoi(argv[1]));

	return 0;
}