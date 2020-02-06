#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100

long int getch(void);
void ungetch(long int);
long int getint(long int *pn);
char buf[BUFSIZE];
long int bufp = 0;
long int c;

long int main()
{
	long int *pn;
	extern long int c;
	
	pn = &c;
	
	while ((c=getchar()) != EOF && c != '\n') {
		getint(pn);
	}
	if (c == '\n') {
		printf("%ld", *pn);
	}
	return 0;
}

long int getint(long int *pn)
{
	long int sign;
	extern long int c;
	
	while (isspace(c = getch())) {
		;
	}
	if(!isdigit(c) && c!= EOF && c!= '+' && c!= '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+') {
		c = getch();
		if (!isdigit(c)) {
			putchar('+');
		}
	}
	if (c == '-') {
		c = getch();
		if (!isdigit(c)) {
			putchar('-');
		}
	}
	for (*pn = 0; isdigit(c); c = getch()) {
		*pn = 10 * *pn + (c - '0');
		*pn  *= sign;
	}
	if (c != EOF) {
		ungetch(c);
	}
	return c;
}

long int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(long int c)
{
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}

