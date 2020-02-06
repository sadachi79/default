#include <stdio.h>

main () 
{
    int c, nr;
	
	nr = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n'){
			++nr;
		}
	printf("%d\n", nr);
}
