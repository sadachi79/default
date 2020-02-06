#include <stdio.h>

main () 
{
    int c, nt;
	
	nt = 0;
	while ((c = getchar()) != EOF)
		if (c == '	'){
			++nt;
		}
	printf("%d\n", nt);
}
