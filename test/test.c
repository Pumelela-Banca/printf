#include "main.h"
#include <stdio.h>
#include "display.c"

int main()
{
	int ll;
	float vv;
	int h;
	
	vv = 35;
	for (ll = 138; ll < 140; ll++)
	{
		//vv /= 0.01;
		h = printf("--%d--", ll);
	}
	printf("%d", h);
	//_countchar("123456");
	return (0);
}

