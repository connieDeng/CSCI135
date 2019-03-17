
#include <iostream>
#include "funcs.h"


// Add your functions here
int sum(int n)
{
	return (n*(n+1))/2;
}

int fact(int n)
{
	if(n > 1)
		return n * fact(n - 1);
	
	else
        return 1;
}