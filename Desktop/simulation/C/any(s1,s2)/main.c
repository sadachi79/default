#include <stdio.h>
#include <stdio.h>
#define MAXLINE 1000

long int i, j, k, nc1, nc2, c1, c2;
char s1[MAXLINE], s2[MAXLINE], s3[MAXLINE];
char m1[MAXLINE], m2[MAXLINE], m3[MAXLINE];

void any(void);
void copy1(void);
void copy2(void);
void copy3(void);

long int main()
{
	extern long int i, j, k, nc1, nc2, c1, c2;
	extern char s1[MAXLINE], s2[MAXLINE];
	
	i = 0;
	j = 0;
	k = 0;
	nc1 = 0;
	nc2 = 0;
	
	while ((c1 = getchar()) != EOF && c1 != '\n') {
		s1[i] = c1;
		copy1();
		++i;
	}
	if (c1 == '\n' && nc1 == 0) {
		nc1 = i;
		s1[i] = c1;
		copy1();
		++i;
	}
	c2 = getchar();
	if (nc1 != 0 && s2[k] != '\n') {
		s2[k] = c2;
		copy2();
		++k;
	}
	if (nc1 != 0 && s2[k] == '\n') {
		nc2 = k;
		i = 0;
		k = 0;
	}
	for (i = 0; i < nc1+1 && m1[i] != '\0'; i++) {
		any();
	}
	return 0;
}

void any(void)
{
	extern long int i, j, k, nc2;
	extern char m1[MAXLINE], m2[MAXLINE], s3[MAXLINE];
	
	for (k = 0; k < nc2+1 && m2[k] != '\0'; k++) {
		if (m1[i] != m2[k] && k < nc2) {
			k++;
		}
		if (m1[i] != m2[k] && k == nc2) {
			s3[j] = m1[i];
			copy3();
			j++;
			k = 0;
			i++;
		}
		if (m1[i] == m2[k]) {
			s3[j] = 127;
			copy3();
			j++;
			k = 0;
			i++;
			printf("%ld", (i+1)/2);
		}
	}
}

void copy1(void)
{
	extern long int i;
	extern char s1[MAXLINE], m1[MAXLINE];
	
	while ((m1[i] = s1[i]) != '\0')
		++i;	
}

void copy2(void)
{
	extern long int k;
	extern char s2[MAXLINE], m2[MAXLINE];
	
	while ((m2[k] = s2[k]) != '\0')
		++k;	
}

void copy3(void)
{
	extern long int j;
	extern char s3[MAXLINE], m3[MAXLINE];
	
	while ((m3[j] = s3[j]) != '\0')
		++j;	
}