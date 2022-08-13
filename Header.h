#pragma once

#include <iostream>
#include <filesystem>
#include <thread>
#include <typeinfo>	
#include <fstream>
#include <string>
#include <set>
#include <concepts>
#include <functional>
#include "boost/thread.hpp"
#include "boost/coroutine/asymmetric_coroutine.hpp"
#include "boost/coroutine2/coroutine.hpp"
#include <mutex>


namespace basycoro = boost::coroutines;
namespace bcoro2 = boost::coroutines2;

namespace quied::source {


	void CoroFibonacci(int&& Limit) {
		boost::coroutines::asymmetric_coroutine<int>::pull_type sourc(
			[&](boost::coroutines::asymmetric_coroutine<int>::push_type& Coro) {
				int first = 1;
				int second = 2;

				Coro(first);
				Coro(second);

				for (int i = 0; i < Limit; ++i) {
					int third = first + second;
					first = second;
					second = third;
					Coro(third);
				}
			});

		for (const auto& el : sourc) { std::cout << el << std::endl; }
	}

	void Coro_push(bcoro2::coroutine<int>::push_type& yield, int value) {

	}

	void Coro_pull(bcoro2::coroutine<int>::pull_type& yield) {

	}

	void pull_test() {
		bcoro2::coroutine<int>::pull_type resume{
			std::bind(Coro_push, std::placeholders::_1, 6) };
		while (resume) {
			std::cout << "called " << resume.get() << std::endl;
			resume();
		}


		bcoro2::coroutine<int>::pull_type resume2{
			std::bind(Coro_push, std::placeholders::_1,3) };

		while (resume2) {
			std::cout << "called " << resume2.get() << std::endl;
			resume2();
		}
	}
}
	void push_test() {

	}


} // namespace source