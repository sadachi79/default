#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

long int getop(char []), sp = 0, getch(void), bufp = 0;
void push(double), ungetch(long int);
double pop(void), val[MAXVAL];
char buf[BUFSIZE];

long int main()
{
	long int type, x, y;
	double op2, op3;
	char s[MAXOP];
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				op2 = pop();
				op3 = pop();
				push(op3 + op2);
				printf("%lf + %lf = %lf", op3, op2, pop());
				break;
			case '*':
				op2 = pop();
				op3 = pop();
				push(op3 * op2);
				printf("%lf * %lf = %lf", op3, op2, pop());
				break;
			case '-':
				op2 = pop();
				op3 = pop();
				push(op3 - op2);
				printf("%lf - %lf = %lf", op3, op2, pop());
				break;
			case '/':
				op2 = pop();
				op3 = pop();
				if (op2 != 0.0) {
					push(op3 / op2);
					printf("%lf / %lf = %lf", op3, op2, pop());
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
					printf("%lf %% %lf = %lf", op3, op2, pop());
				}
				else {
					printf("error: zero divisor\n");
				}
				break;
			case 's':
				op2 = pop();
				push(sin(op2)); 
				printf("sin(%lf) = %lf", op2, pop());
				break;
			case 'e':
				op2 = pop();
				push(exp(op2)); 
				printf("exp(%lf) = %lf", op2, pop());
				break;
			case 'p':
				op2 = pop();
				op3 = pop();
				push(pow(op3, op2)); 
				printf("pow(%lf %lf) = %lf", op3, op2, pop());
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
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
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