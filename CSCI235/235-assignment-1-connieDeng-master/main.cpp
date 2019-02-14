#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main()
{
    std::cout << sum(100);	//5050
	std::cout << fact(5);	//120
	std::cout << factorial(5,1,1,2);	//120
	return 0;
}
