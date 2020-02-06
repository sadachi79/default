#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

long int c, i, nc, sign;
char s[MAXLINE], t[MAXLINE];
double atof(void);
double atofe0(void);
double atofe(void);
double pow(double m, double n);
void copy(void);

double main()
{
	
	extern long int c, i, nc;
	
	i = 0;
	nc = 0;
	
	while ((c = getchar()) != EOF && c != '\n' && c != 'e' && c != 'E') {
		t[i] = c;
		copy();
	}
	if (c == '\n') {
		printf("%lf", atof());
	}
	if (c == 'e' || c == 'E') {
		nc = i;
		while ((c = getchar()) != EOF && c != '\n') {
			t[i] = c;
			copy();
		}
		if (t[nc] != '-') {
			printf("%lf", ((atof() - (t[nc] - '0')) / 10) * pow(10, atofe0()));
		}
		if (t[nc] == '-') {
			printf("%lf", atof() * pow(0.1, atofe()));
		}
	}
	
	return 0;
}

double atof(void)
{
	double val, power;
	extern long int i, sign;
	extern char s[MAXLINE];
	
	for (i = 0; isspace(s[i]); i++) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); ++i) {
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

double atofe0(void)
{
	double val, power;
	extern long int i, sign;
	extern char s[MAXLINE];
	
	for (i = nc; isspace(s[i]); i++) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); ++i) {
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

double atofe(void)
{
	double val, power;
	extern long int i, sign;
	extern char s[MAXLINE];
	
	for (i = nc + 1; isspace(s[i]); i++) {
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); ++i) {
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

double pow(double base, double n)
{
	double j, p;
	
	p = 1;
	for (j = 1; j <= n; ++j) {
		p = p * base;
	}
	return p;
}

void copy(void)
{
	extern long int i;
	extern char s[MAXLINE], t[MAXLINE];
	
	while ((s[i] = t[i]) != '\0') {
		++i;
	}
}

