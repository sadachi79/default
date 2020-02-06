#include <stdio.h>
#include <ctype.h>
#define MAX 1000

char t;
void swap(void);
double atof(char s[]);

main()

{
	int n, c, i, j, k;
	char t, x[MAX], y[MAX];
	
	n = 0;
	i = 0;
	j = 0;
	k = 0;
	
	while ((c=getchar()) != EOF && c != '\n') {
		t = c;
	}
	if (c == '\n') {
		++n;
	}
	if (n = 1) {
		while ((c=getchar()) != EOF && c != '\n') {
			x[j++] = c;
		}
		if (j > 0) {
			x[j+1] = x[j] + x[j-1];
		}
	}
	if (n = 2) {
		while ((c=getchar()) != EOF && c != '\n') {
			y[k++] = c;
		}
		if (k > 0) {
			y[k+1] = y[k] + y[k-1];
		}
	}
	if (n = 3) {
		if (t == 's') {
			printf("%s %s", y, x);
		}
		if (t == 'i') {
			printf("%d %d", y, x);
		}
		if (t == 'l') {
			printf("%ld %ld", y, x);
		}
		if (t == 'f') {
			printf("%f %f", atof(y), atof(x));
		}
		if (t == 'd') {
			printf("%f %f", atof(y), atof(x));
		}
	}
}

double atof(char s[])
{
	double val, power;
	long int i, sign;
	
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