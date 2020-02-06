#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
#define MAX 1000

long int getch(void);
void ungetch(long int);
double getfloat(double *pn);
char buf[BUFSIZE];
long int bufp = 0;
double c;
double atof(char s[]);

long int main()
{
	double *pn;
	extern double c;
	
	pn = &c;
	
	while ((c=getchar()) != EOF && c != '\n') {
		getfloat(pn);
	}
	if (c == '\n') {
		printf("%f", *pn);
	}
	return 0;
}

double getfloat(double *pn)
{
	long int i;
	extern double c;
	char s[MAX];
	
	i = 0;
	
	while (isspace(c = getch())) {
		;
	}
	if(!isdigit(c) && c!= EOF && c!= '+' && c!= '-') {
		ungetch(c);
		return 0;
	}
	for (*pn = 0; isdigit(c); c = getch()) {
		s[i++] = c;
		*pn = atof(s);
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

double atof(char s[])
{
	double val, power;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}