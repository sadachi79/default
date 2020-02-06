#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

long int getop(char []), sp = 0, getch(void), bufp = 0, c;
void push(double), ungetch(long int), itoa(long int n, char s[]), reverse(char s[]);
double pop(void), val[MAXVAL];
char buf[BUFSIZE], var(char []), t;

long int main()
{
	long int type, x, y, li;
	double op2, op3, op4;
	char s[MAXOP], e;
	
	t = '1';
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				e = t;
				break;
			case '+':
				op2 = pop();
				op3 = pop();
				push(op3 + op2);
				printf("%lf*%c + %lf*%c = %lf*%c", op3, e, op2, e, op4 = pop(), e);
				li = op4;
				itoa(li, s);
				push(atof(s));
				break;
			case '*':
				op2 = pop();
				op3 = pop();
				push(op3 * op2);
				printf("%lf*%c * %lf*%c = %lf*%c", op3, e, op2, e, op4 = pop(), e);
				li = op4;
				itoa(li, s);
				push(atof(s));
				break;
			case '-':
				op2 = pop();
				op3 = pop();
				push(op3 - op2);
				printf("%lf*%c - %lf*%c = %lf*%c", op3, e, op2, e, op4 = pop(), e);
				li = op4;
				itoa(li, s);
				push(atof(s));
				break;
			case '/':
				op2 = pop();
				op3 = pop();
				if (op2 != 0.0) {
					push(op3 / op2);
					printf("%lf*%c / %lf*%c = %lf*%c", op3, e, op2, e, op4 = pop(), e);
					li = op4;
					itoa(li, s);
					push(atof(s));
				}
				else {
					printf("error: zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				op3 = pop();
				if (op2 != 0.0) {
					x = op3;
					y = op2;
					push(x % y);
					printf("%lf*%c %% %lf*%c = %lf*%c", op3, e, op2, e, op4 = pop(), e);
					li = op4;
					itoa(li, s);
					push(atof(s));				}
				else {
					printf("error: zero divisor\n");
				}
				break;
			case 's':
				op2 = pop();
				push(sin(op2)); 
				printf("sin(%lf) = %lf", op2, op3 = pop());
				li = op3;
				itoa(li, s);
				push(atof(s));
				break;
			case 'e':
				op2 = pop();
				push(exp(op2)); 
				printf("exp(%lf) = %lf", op2, op3 = pop());
				li = op3;
				itoa(li, s);
				push(atof(s));
				break;
			case 'p':
				op2 = pop();
				op3 = pop();
				push(pow(op3, op2)); 
				printf("pow(%lf %lf) = %lf", op3, op2, op4 = pop());
				li = op4;
				itoa(li, s);
				push(atof(s));
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

void push(double f)
{
	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else {
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

long int getop(char s[])
{
	long int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c!= '.') {
		if (c == '-') {
			if (!isdigit(s[++i] = (c = getch())) && c!= '.') {
				s[i] = '\0';
				if (c != EOF) {
					ungetch(c);
				}
				return '-';
			}
			if (isdigit(c)) {
				while (isdigit(s[++i] = c = getch())) {
					;
				}
			}
			if (c == '.') {
				while (isdigit(s[++i] = c = getch())) {
					;
				}
			}
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
				t = c;
			}
			s[i] = '\0';
			if (c != EOF) {
				ungetch(c);
			}
			return NUMBER;
		}
		if (c == 's') {
			if (c == 'i') {
				if (c == 'n') {
					s[i] = '\0';
					if (c != EOF) {
						ungetch(c);
					}
					return 's';
				}
			}
		}
		if (c == 'e') {
			if (c == 'x') {
				if (c == 'p') {
					s[i] = '\0';
					if (c != EOF) {
						ungetch(c);
					}
					return 'e';
				}
			}
		}
		if (c == 'p') {
			if (c == 'o') {
				if (c == 'w') {
					s[i] = '\0';
					if (c != EOF) {
						ungetch(c);
					}
					return 'p';
				}
			}
		}
		return c;
	}
	i = 0;
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	if (c == '.') {
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
		t = c;
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

long int getch(void)
{
	if (c == EOF) {
		printf("The process is over.");
	}
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(long int c)
{
	if (c == EOF) {
		printf("The process is over.");
	}	
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}

void itoa(long int n, char s[])
{
	long int i, sign;
	
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	long int c, i, j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}