#include "main.h"
#include <stdio.h>
#include "display.c"

int main()
{
	int ll;
	float vv;
	
	vv = 31.5461456;
	for (ll = 0; ll < 5; ll++)
	{
		vv /= 0.01;
		printf("%c\n", 'h');
	}
	//_countchar("123456");
	return (0);
}

