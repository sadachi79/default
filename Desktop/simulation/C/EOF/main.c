#include <stdio.h>

main()
{
    int c; 
	
	for (c = 0; c >= EOF; c = c-1) 
		printf("%d\n", c);
}