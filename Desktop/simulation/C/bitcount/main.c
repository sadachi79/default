#include <stdio.h>

long int main ()
{
    long int b, c;
	
	b = 0;
	
	while ((c = getchar()) != EOF) {
		b += c;
		if ((c == '\n')) {
			b = b & (b-1);
			printf("%ld", b+1);
		}
	}
    return 0;
}
