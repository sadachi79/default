#include <stdio.h>

main()
{
	int c, i;
	int ndigit[128];
	for (i = 0; i < 128; ++i)
		ndigit[i] = 0;
	 
	while ((c = getchar()) != EOF){
		++ndigit[c];
	}
	printf("character freqeuncy =");
	for (i = 0; i < 128; ++i)
		printf(" %d", ndigit[i]);
}