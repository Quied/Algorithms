// #include "Shared.h"
#include "type_algorithms.h"
#include "openssl.h"
#include "common.h"
#include "googletest.h"

#include <iostream>
#include <vector>
#include <functional>

// #include "HTTPRequest.hpp"

int main(int argc,  char **argv) {
	
	quied::source::CoroFibonacci(2);
	quied::source::pull_test();
	quied::source::push_test();


	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}