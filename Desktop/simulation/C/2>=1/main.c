#include <stdio.h>

main () 
{
    int c, ns;
	
	ns = 0;
	while ((c = getchar()) != EOF){
		if (c != ' '){
			putchar(c);
			ns = 0;
		}
		else{
			++ns;
				if (ns == 1){
					putchar(' ');
				}
			}
	}
	printf("%d\n", ns);
}