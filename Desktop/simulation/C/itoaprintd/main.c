#include <stdio.h>
#define MAXLINE 1000

int n, i;
char s[MAXLINE];
int itoa(int n);
char reverse(char s[MAXLINE]);
int strlen(char s[MAXLINE]);

int main()
{
    int c, i;
	extern int n;
	char t[MAXLINE];
	
	n = 0;
	i = 0;
	
	while ((c = getchar()) != EOF && c != '\n') {
		n = n + c;
	}
	if (c == '\n') {
		t[i++] = reverse(itoa(n));
		printf("%s", t);
	}
	return 0;
}

int itoa(int n)
{
	int sign;
	extern int i;
	char s[MAXLINE];
	
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		itoa(n) = n % 10 + '0';
		s[i++] = itoa(n);
	} while ((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i++] = '\0';
	return s[i];
}	

char reverse(char s[MAXLINE])
{
	int c, i, j;
	
	for (i = 0, j = strlen(s); i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	return s[i];
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