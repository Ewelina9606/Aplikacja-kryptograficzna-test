#include <limits>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "operations.h"

#define IS_TRUE(x) { if (!(x)) {std::cout << __FUNCTION__ << ": test failed on line " << __LINE__ << std::endl; return 1;} if (x) {std::cout << __FUNCTION__ << ": test passed on line " << __LINE__ << std::endl; return 0;} }
int tests()
{
	operations operation;
	IS_TRUE(!operation.proba(4));
	IS_TRUE(!operation.proba(6));
	IS_TRUE(operation.proba(7));
}

int main(void) {
	int result = tests();
	return result;
}