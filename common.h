#pragma once
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

std::mutex mtx;
thread_local int count = 42;
static const int t = 100;

void inc(int count) {

	while (count != t) {

		count++;

		{
			std::lock_guard<std::mutex> lock(mtx);
			std::cout << count << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(70));

	}


}
