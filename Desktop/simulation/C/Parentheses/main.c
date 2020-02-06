#include <stdio.h>
#define MAXLINE 1000

long int c, i, nc;

long int s[MAXLINE];
long int m[MAXLINE];

void copy(void);

main()
{
	extern long int c, i, nc;
	extern long int s[MAXLINE];
	extern long int m[MAXLINE];
	
	i=0;
	
	while ((c=getchar())!=EOF && c!=41 && c!=125 && c!=93 && c!=39 && c!=34 && c!='/') {
		s[i] = c;
		copy();
		++i;
	}
	if (c == 41) {
		s[i] = c;
		copy();
		nc = i;
		for (i=0; i<nc; ++i) {
			if (m[i] != 40) {
				printf("-");
			}
			else {
				printf ("Correct");
			}
		}
	}
	if (c == 125) {
		s[i] = c;
		copy();
		nc = i;
		for (i=0; i<nc; ++i) {
			if (m[i] != 123) {
				printf("-");
			}
			else {
				printf ("Correct");
			}
		}
	}
	if (c == 93) {
		s[i] = c;
		copy();
		nc = i;
		for (i=0; i<nc; ++i) {
			if (m[i] != 91) {
				printf("-");
			}
			else {
				printf ("Correct");
			}
		}
	}
	if (c == 39) {
		s[i] = c;
		copy();
		nc = i;
		for (i=0; i<nc-1; ++i) {
			if (m[i] != 39) {
				printf("-");
			}
			else {
				printf ("Correct");
			}
		}
	}
	if (c == 34) {
		s[i] = c;
		copy();
		nc = i;
		for (i=0; i<nc-1; ++i) {
			if (m[i] != 34) {
				printf("-");
			}
			else {
				printf ("Correct");
			}
		}
	}	
	if (c == '/') {
		s[i] = c;
		copy();
		nc = i;
		if (m[nc-3] == '*') {
			for (i=0; i<nc-3; ++i) {
				if (m[i] != '*') {
					printf("-");
				}
				else {
					if (m[i-1] == '/') {
						printf("Correct");
					}
					else {
						printf("-");
					}
				}
			}
		}
		else {
			printf("Correct");
		}
	}
}

void copy(void)
{
	extern long int i;
	extern long int s[MAXLINE];
	extern long int m[MAXLINE];
	
	while ((m[i] = s[i]) != '\0') {
		++i;
	}
}