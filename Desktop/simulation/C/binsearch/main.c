#include <stdio.h>
#define MAXLINE 1000

long int c, i, nc, low, high, mid;
long int v[MAXLINE], mv[MAXLINE], x[MAXLINE], mx[MAXLINE];

void copy(void);
void copyx(void);

long int main()
{
    extern long int low, high, mid;
	extern long int c, i, nc;
	extern long int v[MAXLINE], mv[MAXLINE], x[MAXLINE], mx[MAXLINE];
	
	i = 0;
	nc = 0;
	
	while ((c = getchar()) != EOF && c != '\n' && nc == 0) {
		v[i] = c;
		copy();
	}
	if (c == '\n' && nc == 0) {
		nc = i;
		++i;
	}
	while ((c = getchar()) != EOF && c != '\n') {
		x[i] = c;
		copyx();
		printf("%ld", mx[i-1]);
	}
	if (i > nc && c == '\n') {
		low = mv[0];
		high = mv[nc-1];
		mid = (low + high) / 2;
		if (mx[i-1] < mv[mid]) {
			mid = (low + mid) / 2;
			high = mid;
			printf("%ld", mv[mid]);
		}
		if (mx[i-1] > mv[mid]) {
			mid = (mid + high) / 2;
			low = mid;
			printf("%ld", mv[mid]);
		}
		if (mx[i-1] == mv[mid]) {
			printf("%ld", mv[mid]);
		}
	}
	return -1;
}

void copy(void)
{
	extern long int i;
	extern long int v[MAXLINE], mv[MAXLINE];
	
	while ((mv[i] = v[i]) != '\0') {
		++i;
	}
}

void copyx(void)
{
	extern long int i;
	extern long int x[MAXLINE], mx[MAXLINE];
	
	while ((mx[i] = x[i]) != '\0') {
		++i;
	}
}