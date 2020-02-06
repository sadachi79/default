#include <stdio.h>

long int n, i, ncx;
unsigned long c1, x, y;

long int main()
{
	extern long int n, i, ncx;
	extern unsigned long c1, x, y;
	
	n = 2;
	
	i = 0;
	ncx = 0;
	c1 = y = x = 0;
	
	while ((c1 = getchar()) != EOF && c1 != '\n') {
		x = x + c1;
		y = y + c1;
		++i;
	}
	if (c1 == '\n' && ncx == 0) {
		x = x + c1;
		y = y + c1;
		ncx = i;
		++i;
	}
	if (ncx != 0 && c1 == '\n') {
		y << (ncx-n+1);
		x >> (ncx-n+1-n);
		x + y;
		printf("%ld %ld %ld", x, y, x+y);
	}
	return 0;
}