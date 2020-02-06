#include <stdio.h>

long int p, n, i, k, ncx, ncy;
unsigned long c1, c2, x, y;

long int main()
{
	extern long int p, n, i, k, ncx, ncy;
	extern unsigned long c1, c2, x, y;
	
	p = 1;
	n = 2;
	
	i = 0;
	k = 0;
	ncx = 0;
	ncy = 0;
	c1 = x = 0;
	c2 = y = 0;
	
	while ((c1 = getchar()) != EOF && c1 != '\n') {
		x = x + c1;
		y = y + c1;
		++i;
	}
	if (c1 == '\n' && ncx == 0) {
		x = x + c1;
		ncx = i;
		y = y + c1;
	}
	if (ncx != 0 && c2 == '\n') {
		y >> (p+1-n);
		(x >> (p+1-n)) & (~y << n);
		printf("%ld %ld", x, y);
	}
	return 0;
}