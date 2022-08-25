// #include "Shared.h"
//#include "type_algorithms.h"
#include "openssl.h"
#include "common.h"
//#include "googletest.h"
#include "Wireless.h"

#include <iostream>
#include <vector>
#include <functional>

// #include "HTTPRequest.hpp"



int main(int argc,  char **argv) {
	
	//quied::source::CoroFibonacci(2);
	//quied::source::pull_test();
	//quied::source::push_test();

	//	quied::any::QAny a(3);
	// std::cout << quied::any::QAny::any_cast<int>(a) << std::endl;


	// -------------
	boost::process::ipstream pipe;
	boost::process::child a("gcc --version", boost::process::std_out > pipe);

	std::string str;

	while (pipe && std::getline(pipe, str) && !str.empty())
		std::cerr << str << std::endl;

	a.wait();
	// -----------------------



	//testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}