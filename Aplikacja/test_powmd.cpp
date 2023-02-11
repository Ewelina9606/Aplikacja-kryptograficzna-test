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
	IS_EQUAL(operation.powmd(97, 13, 35), 27);
	IS_EQUAL(operation.powmd(101, 17, 35), 26);
	IS_NOT_EQUAL(operation.powmd(56, 87, 12), 4);

}

int main(void) {
	int result = tests();
	return result;
}