#include <stdio.h>

float cel(float f);

main()
{
	float f;
	
	printf("%6.1f\n", cel(f));
	return 0;
}

float cel(float f)
{
	float s, c;
	
	scanf("%f", &s);
	c = (5.0/9.0) * (s-32.0);
	return c;
}