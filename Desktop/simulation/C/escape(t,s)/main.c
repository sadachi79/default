#include <stdio.h>
#define MAXLINE 1000

long int c, i;
char s[MAXLINE], t[MAXLINE];

void copy(void);

long int main()
{
    extern long int c, i;
	extern char s[MAXLINE], t[MAXLINE];
	
	i = 0;
	
	while ((c = getchar()) != EOF && i<10) {
		switch (c) {
			case 92:
				t[i] = 92;
				copy();
				c = getchar();
				switch (c) {
					case 110:
						i = i-1;
						t[i] = 10;
						copy();
						break;
					case 116:
						i = i-1;
						t[i] = 9;
						copy();
						break;
					default:
						t[i] = c;
						copy();
						break;
				}
				break;
			default:
				t[i] = c;
				copy();
				break;
		}
	}
	i = 0; 
	for (i = 0; i < 10; ++i) {
		printf("%c", s[i]);
	}
	return 0;
}

void copy(void)
{
	extern long int i;
	extern char s[MAXLINE], t[MAXLINE];
	
	while ((s[i] = t[i]) != '\0') {
		++i;
	}
}
