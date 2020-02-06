#include <stdio.h>
#define MAXLINE 1000

int n, i, b;
char s[MAXLINE];
void itob(int n, char s[MAXLINE], int b);
void reverse(char s[MAXLINE]);
int strlen(char s[MAXLINE]);

int main()
{
    int c;
	extern int n, i, b;
	extern char s[MAXLINE];
	
	b = 16;
	
	n = 0;
	
	while ((c = getchar()) != EOF && c != '\n') {
		n = n + c;
	}
	if (c == '\n') {
		itob(n, s, b);
		for (i = 0; i < MAXLINE-1; ++i) {
			printf("%c", s[i]);
		}
	}
	return 0;
}

void itob(int n, char s[MAXLINE], int b)
{
	int sign;
	char m[MAXLINE];
	extern int i;
	
	if ((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		m[i] = n % b + '0';
		if (m[i] <= '9') {
			s[i] = m[i];
			i++;
		}
		else {
			s[i] = m[i] - '9' + 64;
			i++;
		}
	} while ((n /= b) > 0);
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