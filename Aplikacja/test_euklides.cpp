#include <limits>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "operations.h"

#define IS_EQUAL(x,y) { if (!(x == y)) {std::cout << __FUNCTION__ << ": test failed on line " << __LINE__ << std::endl; return 1;} if (x == y) {std::cout << __FUNCTION__ << ": test passed on line " << __LINE__ << std::endl; return 0;} }
#define IS_NOT_EQUAL(x,y) { if (x == y) {std::cout << __FUNCTION__ << ": test failed on line " << __LINE__ << std::endl; return 1;} if (!(x == y)) {std::cout << __FUNCTION__ << ": test passed on line " << __LINE__ << std::endl; return 0;} }

int tests()
{
	operations operation;

	IS_EQUAL(operation.euklides(13, 24), 13);
	IS_EQUAL(operation.euklides(37, 468), 253);
	IS_NOT_EQUAL(operation.euklides(35, 677), 987);
}

int main(void) {
	int result = tests();
	return result;
}