#include <stdio.h>
#define MAXLINE 1000

long int c, i, nc;
char s[MAXLINE], m[MAXLINE];

void copy(void);

long int main()
{
	extern char s[MAXLINE];
	extern long int c, i, nc;
	
	i = 0;
	nc = 0;
	
	while ((c = getchar()) != EOF) {
		s[i] = (c <= 64 || c >= 91) ? c : c+32;
		copy();
		++i;
		if (c == '\n') {
			nc = i;
			i = 0;
			for (i=0; i<nc+1; ++i) {
				printf("%c", s[i]);
			}
		}
	}
	return 0;
}
		
void copy(void)
{
	extern long int i;
	extern char s[MAXLINE], m[MAXLINE];
		
	while ((m[i] = s[i]) != '\0')
		++i;	
}
		
