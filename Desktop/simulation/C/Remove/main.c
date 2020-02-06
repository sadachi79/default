#include <stdio.h>
#define MAXLINE 1000

long int getline(char line[], long int maxline);

main()
{
	long int len;
	char line[MAXLINE];
	
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > 0)
			printf("%ld %s", len, line);
	return 0;
}

long int getline(char s[], long int lim)
{
	char c;
	long int i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n' || c == '\b') {
		if (c == ' ' || c == '	') {
			s[i] = '\b';
			--i;
		}
		else {
			s[i] = '\n';
			++i;
		}
	}
	s[i+1] = '\0';
	return i;
}