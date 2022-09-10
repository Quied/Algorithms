#include "Shared.h"
//#include "type_algorithms.h"
#include "openssl.h"
#include "common.h"
//#include "googletest.h"
// #include "Wireless.h"
#include "boost/process.hpp"
#include <memory>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
// #include "HTTPRequest.hpp"



void TL::show(int a) {
	std::cout << a + a << std::endl;
}

int main(int argc,  char **argv) {

	/*
	// utils::unique_ptr<int>::frow(42);
	
	auto t = std::unique_ptr<TL>(new TL);
	t->show(22);

	std::unique_ptr<TL> NT;
	NT->show(33);

	TL a;
	a.show(42);
	*/

	int x = 5;
	utills::unique_ptr<int> ptr(&x);
	
	utills::unique_ptr<int> ptr2(ptr);
	




	// std::cout << sizeof(t);
	//testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}