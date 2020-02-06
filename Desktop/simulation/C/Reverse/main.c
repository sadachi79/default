#include <stdio.h>
#define MAXLINE 1000

void reverse(char l[], long int maxline);

main()
{
	char l[MAXLINE];
	
	reverse(l, MAXLINE);
	printf("\n");
	return 0;
}

void reverse(char s[], long int lim)
{
	long int i, j, c;

	i = 0;
	j = 0;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		s[i] = c;
		++i;
	}
	
	if (c == '\n') {
		for (j=0; j<i+1; ++j) {
			printf("%c", s[i-j]);
		}
	}
}