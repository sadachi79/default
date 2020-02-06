#include <stdio.h>

main () 
{
    int c, nc;
	
	nc = 0;
	
	while ((c = getchar()) != EOF && c != '\n' && c != '\b') {
		++nc;
		if (nc == 8 || c == '\n') {
			nc = 0;
		}
		if (c == '\b') {
			nc = nc-1;
		}
		if (c != '	') {
			putchar(c);
		}
		else {
			if (nc == 0) { 
				printf("         ");
			}
			if (nc == 1) {
				printf("        ");
			}
			if (nc == 2) {
				printf("       ");
			}
			if (nc == 3) {
				printf("      ");
			}
			if (nc == 4) { 
				printf("     ");
			}
			if (nc == 5) { 
				printf("    ");
			}
			if (nc == 6) { 
				printf("   ");
			}
			if (nc == 7) { 
				printf("  ");
			}
		}
    }
}