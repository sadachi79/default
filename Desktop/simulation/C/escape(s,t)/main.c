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
			case '\n':
				s[i] = '\\';
				copy();
				s[i] = 'n';
				copy();
				break;
			case '	':
				s[i] = '\\';
				copy();
				s[i] = 't';
				copy();
				break;
			default:
				s[i] = c;
				copy();
				break;
		}
	}
	i = 0; 
	for (i = 0; i < 10; ++i) {
		printf("%c", t[i]);
	}
	return 0;
}

void copy(void)
{
	extern long int i;
	extern char s[MAXLINE], t[MAXLINE];
				
	while ((t[i] = s[i]) != '\0') {
				++i;
	}
}