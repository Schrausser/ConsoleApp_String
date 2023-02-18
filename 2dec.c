//----------------------------------------------------------------------------------------| 2DEC von Dietmar Schrausser 2009
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
	printf("2DEC [x]\n");
	for(lauf=1;lauf<=17;lauf++)cprintf("\xC4"); printf("\n");
	printf("[x] .... Argument\n");
	for(lauf=1;lauf<=17;lauf++)cprintf("\xC4"); printf("\n");
	printf("2DEC von Dietmar Schrausser\n");
    printf("compiliert %s @ %s\n", __DATE__, __TIME__);
	exit(1);
}
                  
int main(int argc, char *argv[])
{
	int iLauf, sw=1, index1=0, zlr=1, zlr1=1, index=0, zahl_;
	char zahl [21], zahl_okt[21], tmp[21];

	if(argc != 2) _profil();
	
	zahl_ = atoi(argv[1]); 
	sprintf(zahl_okt,"%i", zahl_);
	
	sprintf(zahl,"%s", argv[1]);
		
	if(strcmp(argv[1],zahl_okt) == 0) 
	for(iLauf = 0; iLauf <= 1000000; iLauf++)
	{
		strcpy(tmp," "); sprintf (tmp, "%o", iLauf);
		if(atoi(tmp) == atoi(argv[1])) {printf ("\noktal = %s -> dezimal = %i",argv[1], iLauf);break; }
	}
	
	printf ("\nberechne...");
	for(iLauf = zahl_; iLauf <= 10000000; iLauf++)
	{
		strcpy(tmp," "); sprintf (tmp, "%X", iLauf);//printf("%s %s\n", zahl, tmp);
		if(strcmp(tmp,zahl) == 0) {printf ("\rhexadezimal = %s -> dezimal = %i\n",argv[1], iLauf);exit(1); }
	}
	printf ("\r%s keine Uebereinstimmung\n",argv[1]);
	
	return 0;
}