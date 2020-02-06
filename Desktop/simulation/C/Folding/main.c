#include <stdio.h>
#define MAXLINE 1000

long int c, i, nc;

char s[MAXLINE];
char m[MAXLINE];

long int getline(void);
void copy(void);

main()
{
	extern long int c, i, nc;
	extern char s[MAXLINE];
	extern char m[MAXLINE];
	
	i=0;
	nc=0;
	
	while ((c=getchar())!=EOF && c!='\n') {
		s[i] = c;
		copy();
		++i;
	}
	if (c == '\n') {
		if (s[i-1] == ' ' || s[i-1] == '	') {
			s[i-1] = '\b';
			copy();
			i = i-1;
		}
		if (s[i-1]!=' ' && s[i-1]!='	') {
			s[i] = '\n';
			copy();
			nc = i;
			for (i=0; i<nc+1; ++i) {
					printf("%c", m[i]);
					++i;
			}
		}
	}
}

void copy(void)
{
	extern long int i;
	extern char s[MAXLINE];
	extern char m[MAXLINE];
	
	while ((m[i] = s[i]) != '\0') {
		++i;
	}
}