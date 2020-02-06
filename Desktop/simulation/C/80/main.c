#include <stdio.h>
#define MAXLINE 1000

long int getline(char line[], long int maxline);

main()
{
	long int len;
	char line[MAXLINE];
	
	while ((len = getline(line, MAXLINE)) > 80)
		if (len > 80)
			printf("%ld %s", len, line);
	return 0;
}

long int getline(char s[], long int lim)
{
	char c;
	long int i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}