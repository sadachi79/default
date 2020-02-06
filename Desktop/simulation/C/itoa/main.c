#include <stdio.h>
#define MAXLINE 1000

int n, i;
char s[MAXLINE];
void itoa(int n, char s[MAXLINE]);
void reverse(char s[MAXLINE]);
int strlen(char s[MAXLINE]);

int main()
{
    int c;
	extern int n, i;
	extern char s[MAXLINE];
	
	n = 0;
	
	while ((c = getchar()) != EOF && c != '\n') {
		n = n + c;
	}
	if (c == '\n') {
		itoa(n, s);
		for (i = 0; i < MAXLINE-1; ++i) {
			printf("%c", s[i]);
		}
	}
	return 0;
}

void itoa(int n, char s[MAXLINE])
{
	int sign;
	extern int i;
	
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

void reverse(char s[MAXLINE])
{
	int c, i, j;
	
	for (i = 0, j = strlen(s); i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

int strlen(char s[MAXLINE])
{
	int i;
	
	i = 0;
	while (s[i] != '\0') {
		++i;
	}
	return i;
}