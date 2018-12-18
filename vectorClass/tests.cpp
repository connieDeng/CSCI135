#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "methods.h"

TEST_CASE("Insert At Location"){
  SECTION("Valid input"){
    MyVector<int> t(5,2,3,4,5);
    t.insertLocation(0,3);
    CHECK(t.data[0] == 3);
    t.insertLocation(3,6);
    CHECK(t.data[3] == 6);
  }
}

TEST_CASE("Insert At End"){
  SECTION("Valid input"){
    MyVector<int> t(5,2,3,4,5);
    t.insertEnd(14);
    CHECK(t.data[5] == 14);
    t.insertEnd(1);
    CHECK(t.data[6] == 1);
  }
}

TEST_CASE("Delete At Location"){
  SECTION("Valid input"){
    MyVector<int> t(5,2,3,4,5);
    t.deleteLocation(4);
    CHECK(t.data[3] == 4);
    t.deleteLocation(3);
    CHECK(t.data[2] == 3);
  }
}

/*
  Figure out a way to access the data array to conduct tests for it.
OTherwise might need to print everything in the main function and update the readme file to account for the changes.

 */

