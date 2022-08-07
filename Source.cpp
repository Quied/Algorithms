#include "type_algorithms.h"
#include <iostream>
#include <vector>
#include <functional>


int main() {

//	std::vector<int> Vec{ 1,2,3,4,5,6,7,8,9 };
//	boost::thread_group threads;
//	auto h = std::bind(sh, std::placeholders::_2, 2);


	boost::asio::io_context context;
	boost::asio::steady_timer tmr(context, boost::asio::chrono::seconds(1));

	int count{1};


	tmr.async_wait(boost::bind(quied::wless::error, 
		boost::asio::placeholders::error, &tmr, &count));

	context.run();

}