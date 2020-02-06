#include <stdio.h>
#define MAXLINE 1000

long int c, nc, i;

char s[MAXLINE];
char m[MAXLINE];

long int getline(void);
void copy(void);

main () 
{
    extern long int c, nc;
	
	nc = 0;
	
		getline();
		if (c != ' ') {
			putchar(c);
		}
		else {
			if (nc == 0) {
				++nc;
				c = getchar();
				if (c == '	') {
					copy();
					printf("	");
				}
				else {
					c = getchar();
					if (c == '	') {
						copy();
						printf("	");
					}
					else {
						c = getchar();
						if (c == '	') {
							copy();
							printf("	");
						}
						else {
							c = getchar();
							if (c == '	') {
								copy();
								printf("	");
							}
							else {
								c = getchar();
								if (c == '	') {
									copy();
									printf("	");
								}
								else {
									c = getchar();
									if (c == '	') {
										copy();
										printf("	");
									}
									else {
										c = getchar();
										if (c == '	') {
											copy();
											printf("	");
										}
									}
								}
							}
						}
					}
				}
			}
			if (nc == 1) {
				++nc;
				c = getchar();
				if (c == '	') {
					copy();
					printf("	");
				}
				else {
					c = getchar();
					if (c == '	') {
						copy();
						printf("	");
					}
					else {
						c = getchar();
						if (c == '	') {
							copy();
							printf("	");
						}
						else {
							c = getchar();
							if (c == '	') {
								copy();
								printf("	");
							}
							else {
								c = getchar();
								if (c == '	') {
									copy();
									printf("	");
								}
								else {
									c = getchar();
									if (c == '	') {
										copy();
										printf("	");
									}
									else {
										c = getchar();
										if (c == '	') {
											copy();
											printf("	");
										}
									}
								}
							}
						}
					}
				}
			}
			if (nc == 2) {
				++nc;
				c = getchar();
				if (c == '	') {
					copy();
					printf("	");
				}
				else {
					c = getchar();
					if (c == '	') {
						copy();
						printf("	");
					}
					else {
						c = getchar();
						if (c == '	') {
							copy();
							printf("	");
						}
						else {
							c = getchar();
							if (c == '	') {
								copy();
								printf("	");
							}
							else {
								c = getchar();
								if (c == '	') {
									copy();
									printf("	");
								}
								else {
									c = getchar();
									if (c == '	') {
										copy();
										printf("	");
									}
								}
							}
						}
					}
				}
			}
			if (nc == 3) {
				++nc;
				c = getchar();
				if (c == '	') {
					copy();
					printf("	");
				}
				else {
					c = getchar();
					if (c == '	') {
						copy();
						printf("	");
					}
					else {
						c = getchar();
						if (c == '	') {
							copy();
							printf("	");
						}
						else {
							c = getchar();
							if (c == '	') {
								copy();
								printf("	");
							}
							else {
								c = getchar();
								if (c == '	') {
									copy();
									printf("	");
								}
							}
						}
					}
				}
			}
			if (nc == 4) {
				++nc;
				c = getchar();
				if (c == '	') {
					copy();
					printf("	");
				}
				else {
					c = getchar();
					if (c == '	') {
						copy();
						printf("	");
					}
					else {
						c = getchar();
						if (c == '	') {
							copy();
							printf("	");
						}
						else {
							c = getchar();
							if (c == '	') {
								copy();
								printf("	");
							}
						}
					}
				}
			}
			if (nc == 5) {
				++nc;
				c = getchar();
				if (c == '	') {
					copy();
					printf("	");
				}
				else {
					c = getchar();
					if (c == '	') {
						copy();
						printf("	");
					}
					else {
						c = getchar();
						if (c == '	') {
							copy();
							printf("	");
						}
					}
				}
			}
			if (nc == 6) {
				++nc;
				c = getchar();
				if (c == '	') {
					copy();
					printf("	");
				}
				else {
					c = getchar();
					if (c == '	') {
						copy();
						printf("	");
					}
				}
			}
			if (nc == 7) {
				++nc;
				c = getchar();
				if (c == '	') {
					copy();
					printf("	");
				}
			}
		}
		copy();
		printf("%s", m);
}

long int getline(void)
{
	extern long int c, nc, i;
	extern char s[MAXLINE];
	
	nc = 0;
	i = 0;

	for (i=0; i<MAXLINE-1 && (c=getchar())!=EOF && c!='\b' && c!= '\n'; ++i) {
		s[nc] = c;
		++nc;
	}
	if (c == '\b') {
		nc = nc-1;
	}
	if (nc == 8 || nc == '\n') {
		nc = 0;
		++i;
	}
	return s[nc];
}

void copy(void)
{
	extern long int nc;
	extern char s[MAXLINE];
	extern char m[MAXLINE];

	nc = 0;
	while ((m[nc] = s[nc]) != '\0') {
		++nc;
	}
}