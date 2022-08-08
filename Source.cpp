#include "type_algorithms.h"
#include "common.h"
#include <iostream>
#include <vector>
#include <functional>


int main() {

//	std::vector<int> Vec{ 1,2,3,4,5,6,7,8,9 };
//	boost::thread_group threads;
//	auto h = std::bind(sh, std::placeholders::_2, 2);


	boost::asio::io_context context;

	quied::wless::Wls pnt(context);
	boost::thread t(boost::bind(&boost::asio::io_context::run, &context));

	t.join();
	context.run();








}