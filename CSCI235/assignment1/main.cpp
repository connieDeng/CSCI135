#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main()
{
    std::cout << sum(100) << std::endl << fact(5);
	return 0;
}
