#include <stdio.h>
#define MAXLINE 1000

long int i, n, c, nc;
char s[MAXLINE], m[MAXLINE];

long int htoi(void);
void copy(void);

main()
{
	extern long int i, n, c, nc;
	extern char s[MAXLINE];
	
	i = 0;
	n = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		copy();
		++i;
	}
	if (c == '\n') {
		nc = i;
	}
	for (i = 0; i < nc && ((m[i] >= '0' && m[i] <= '9') || (m[i] >= 'A' && m[i] <= 'F') || (m[i] >= 'a' && m[i] <= 'f')); ++i) {
		htoi();
		++i;
	}
	printf("%ld", (long int) n);
}

long int htoi(void)
{
    extern long int i, n;
	extern char m[MAXLINE];
	
	if (m[i] >= '0' && m[i] <= '9') {
		n = 16 * n + (m[i] - '0');
	}
	if (m[i] >= 'A' && m[i] <= 'F') {
		n = 16 * n + (m[i] - 'A' + 10);
	}
	if (m[i] >= 'a' && m[i] <= 'f') {
		n = 16 * n + (m[i] - 'a' + 10);
	}
	return n;
}

void copy(void)
{
	extern long int i;
	extern char s[MAXLINE], m[MAXLINE];

	while ((m[i] = s[i]) != '\0')
		++i;
}