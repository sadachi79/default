#include <stdio.h>
#define MAXLINE 1000

int reverse(char s[MAXLINE]);
int nc;

main()
{
	char s[MAXLINE];
	int c, i;
	extern int nc;
	
	i = 0;
	
	while ((c = getchar()) != EOF && c != '\n') { 
		s[i] = c;
		while (s[i] != '\0') {
			++i;
		}
		nc = i;
	}
	if (c == '\n') {
		reverse(s);
		for (i = 0; i < nc + 1; ++i) {
			printf("%c", s[i]);
		}
	}
	return 0;
}

int reverse(char s[MAXLINE])
{
	int c, j;
	extern int nc;
	
	for (j = nc; j > -1; j--) {
		c = reverse(s);
		reverse(s) = s[j];
		s[j] = c;
	}
	return s;
}