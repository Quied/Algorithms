#pragma once

#include <iostream>
#include <filesystem>
#include <thread>
#include <typeinfo>	
#include <fstream>
#include <string>
#include <set>
#include <mutex>
#include <concepts>
#include <functional>
#include <future>
#include <numeric>

#include "boost/thread.hpp"
#include "boost/coroutine/asymmetric_coroutine.hpp"
#include "boost/coroutine2/coroutine.hpp"



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
		for (int i = 0; i < value; i++) {
			std::cout << "push: " << i << std::endl;
			yield(i);
		}
	}

	void Coro_pull(bcoro2::coroutine<int>::pull_type& yield) {
		int ron = 0;

		while (yield){
			std::cout << "pulled: " << ron << std::endl;
			auto t = yield.get();
			yield();
			ron++;
		}
	}

	void pull_test() {
		bcoro2::coroutine<int>::pull_type resume{ std::bind(Coro_push, std::placeholders::_1, 6) };

		while (resume) {
			std::cout << "called " << resume.get() << std::endl;
			resume();
		}


		bcoro2::coroutine<int>::pull_type resume2{ std::bind(Coro_push, std::placeholders::_1,3) };
		for(const auto &el : resume2) {
			std::cout << "for: " << el << std::endl;
		}

	}

	void push_test() {
		bcoro2::coroutine<int>::push_type sink{ Coro_pull };
		std::vector<int> Vec{ 42,12,124,5 };
		for (const int& el : Vec) {
			std::cout << "Sink: " << el << std::endl;
			sink(el);
		}
	}






} // namespace source