#include <iostream>
#include "funcs.h"


// Add your functions here
int sum(int n)
{
	return(1+n)*(n/2);
}

int fact(int n)
{
	if(n > 1)
		return n * fact(n - 1);
	
	else
        return 1;
}

int factorial(int n, int a, int b, int c)
{
	if (n==0)
		return a;
	else
		return factorial(n-1,b,c,b+c);
}