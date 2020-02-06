#include <stdio.h>
#define lim 1000

main()
{
	long int i;
	char c, s[lim];
	
	i=0; 
	
	for (i=0; i<lim-1; ++i) {
		while ((c=getchar()) != '\n') {
			while (c != EOF) {
				s[i] = c;
			}
		}
	}
}