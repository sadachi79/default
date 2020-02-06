#include <stdio.h>

main () 
{
    int c, ns;
		
	ns = 0;
	while ((c = getchar()) != EOF)
		if (c == ' '){
			++ns;
		}
	printf("%d\n", ns);
}
