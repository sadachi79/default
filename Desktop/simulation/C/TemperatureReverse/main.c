#include <stdio.h>

main()
{
    float celsius, fahr;
	int lower, upper, step;
	
	lower = 0;
	upper = 150;
	step = 10; 
	
	printf("Scale Exchange from Celsius to Fahrenheit\n");
	
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}