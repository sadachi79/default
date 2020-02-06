#include <stdio.h>

main()
{
	int c, nc, i;
	int ndigit[33];
	for (i = 0; i < 33; ++i)
		ndigit[i] = 0;

	nc = 0; 
	while ((c = getchar()) != EOF){
		if (c != ' ' && c != '\n' && c != '\t'){
			++nc;
		}
		else {
			++ndigit[nc-1];
			nc = 0;
		}
	}
	printf("word length =");
	for (i = 0; i < 33; ++i)
		printf(" %d", ndigit[i]);
}