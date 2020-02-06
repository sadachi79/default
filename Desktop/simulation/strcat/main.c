#include <stdio.h>

void strcat(char *s, char *t);
char *s, *t;

long int main()
{
	long int nc, c, c2, i, j;
	extern char *s, *t;
	
	nc = 0;
	i = j = 0;
	
	while ((c = getchar()) != EOF && c != '\n' && nc == 0) {
		s = &c;
		++i;
	}
	if (c == '\n') {
		nc = i;
	}
	while ((c2 = getchar()) != EOF && c2 != '\n' && nc != 0) {
		t = &c2;
		++j;
	}
	if (c2 == '\n' && j > 0) {
		nc = i + j;
		printf("%s", s);
		printf("%s", t);
		strcat(s, t);
		printf("%s", s);
	}
	return 0;
}

void strcat(char *s, char *t)
{
	while (*s != '\0') {
		*s++;
	}
	while ((*s++ = *t++) != '\0') {
		;
	}
}