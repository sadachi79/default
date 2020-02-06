#include <stdio.h>

main () 
{
    int c;
	
	while ((c = getchar()) != EOF){
		if (c == '	'){
			printf("%c%c", '\\', 't');
		}
		else{
			if (c == '\b'){
				printf("%c%c", '\\', 'b');
			}
			else{
				if (c == '\\'){
					printf("%c%c", '\\', '\\');
				}
				else{
					putchar(c);
				}
			}
		}
	}
}