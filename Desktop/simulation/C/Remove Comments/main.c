#include <stdio.h>
#define MAXLINE 1000

void copy(void);

long int i, l;
char c;
char s[MAXLINE];
char m[MAXLINE];

main()
{
	extern long int i, l;
	extern char c;
	extern char s[MAXLINE];
	extern char m[MAXLINE];

	i=0;
	
	while ((c=getchar())!=EOF && c!='/' && c!='\n') {
		s[i] = c;
		copy();
		putchar(c);
		++i;
	}
	if (c == '/') {
		s[i] = c;
		copy();
		++i;
		if (s[i]!='*') {
			printf("%c", m[i-1]);
			s[i] = c;
			copy();
			printf("%c", m[i]);
			++i;
		}
		if (c == '*') {
			putchar('\b');
			++i;
		}
	}
	if (c == '\n') {
		s[i] = c;
		copy();
		putchar(c);
		++i;
		l = i;
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