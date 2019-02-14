#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

TEST_CASE("Testing Sum"){
  CHECK(sum(0)==0);
  CHECK(sum(5)==15);
 }


TEST_CASE("Testing Factorial"){
  CHECK(fact(5)==120);
  CHECK(fact(2)==2);
  CHECK(fact(0)==1);
}






