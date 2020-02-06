#include <stdio.h>
#define MAXLINE 1000

long int c, i, j, nc, nct;
char s1[MAXLINE], s2[MAXLINE];

void copy(void);

long int main()
{
    extern long int c, i, j, nc, nct;
	extern char s1[MAXLINE], s2[MAXLINE];
	
	i = 0;
	j = 0;
	nc = 0;
	nct = 0;
	
	while ((c = getchar()) != EOF && c != '\n') {
		switch (c) {
			case 'a':
				j = 0;
				s1[i] = c;
				copy();
				if ((c = getchar()) == 45) {
					c = getchar();
					nc = c - 97;
					for (j = 0; j < nc; ++j) {
						s1[i] = 97 + j + 1;
						copy();
					}
				}
				else {
					s1[i] = c;
					copy();
				}
				break;
			case 'A':
				j = 0;
				s1[i] = c;
				copy();
				if ((c = getchar()) == 45) {
					c = getchar();
					nc = c - 65;
					for (j = 0; j < nc; ++j) {
						s1[i] = 65 + j + 1;
						copy();
					}
				}
				else {
					s1[i] = c;
					copy();
				}
				break;
			case '0':
				j = 0;
				s1[i] = c;
				copy();
				if ((c = getchar()) == 45) {
					c = getchar();
					nc = c - 48;
					for (j = 0; j < nc; ++j) {
						s1[i] = 48 + j + 1;
						copy();
					}
				}
				else {
					s1[i] = c;
					copy();
				}
				break;
			default:
				s1[i] = c;
				copy();
				break;
		}
	}
	if (c == '\n') {
		nct = i; 
		for (i = 0; i < nct+1; ++i) {
			printf("%c", s2[i]);
		}
	}
	return 0;
}

void copy(void)
{
	extern long int i;
	extern char s1[MAXLINE], s2[MAXLINE];
	
	while ((s2[i] = s1[i]) != '\0') {
		++i;
	}
}