#include <stdio.h>
#define MAXLINE 1000

long int i, j, k, c, nc, nc2;
char s[MAXLINE], t[MAXLINE], ms[MAXLINE], mt[MAXLINE];
long int strrindex(void);
void copys(void);
void copyt(void);

long int main()
{
	extern char s[MAXLINE], t[MAXLINE], ms[MAXLINE], mt[MAXLINE];
	extern long int c, nc, nc2;
	extern long int i, k;
	
	i = 0;
	k = 0;
	nc = 0;
	nc2 = 0;
	
	while (nc == 0 && (c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		t[k] = c;
		copys();
	}
	if (nc == 0 && c == '\n') {
		nc = i;
		s[i] = c;
		t[k] = c;
		copys();
	}
	c = getchar();
	while (nc != 0 && c != EOF && t[k] != '\n') {
		s[i] = c;
		t[k] = c;
		copyt();
	}
	if (nc != 0 && c != EOF && t[k] == '\n') {
		nc2 = k;
		s[i] = c;
		t[k] = c;
		copyt();
		for (i=0; i<nc+1; ++i) {
			printf("%c", ms[i]);
		}
		for (k=0; k<nc2+1; ++k) {
			printf("%c", mt[k]);
		}
		printf("%ld %ld %ld", i, k, nc);
		printf("%ld", strrindex());
	}
	return 0;
}

long int strrindex(void)
{
	extern long int i, j, k;
	extern char ms[MAXLINE], mt[MAXLINE];
	
	i = nc;
	j = 0;
	k = 0;

	for (i = nc; ms[i] != '\0'; i--) {
		for (j=i, k=0; mt[k]!='\0' && ms[j]==mt[k]; j++, k++) {
			;
		}
		if (k > 0 && mt[k] == '\0') {
			return i;
		}
	}
	return -1;
}

void copys(void)
{
	extern long int i;
	extern char s[MAXLINE], ms[MAXLINE];
		
	while ((ms[i] = s[i]) != '\0') {
		++i;
	}
}

void copyt(void)
{
	extern long int k;
	extern char t[MAXLINE], mt[MAXLINE];
		
	while ((mt[k] = t[k]) != '\0') {
		++k;
	}
}