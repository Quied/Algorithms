#include "type_algorithms.h"
#include <iostream>
#include <vector>


int main() {

	std::vector<int> Vec{ 2,4,8,16,32,64,128,256,512,1024 };

   // quied::Same::set_as(Vec.begin(), Vec.end(), [](int a) { return a == 4; });
   // std::cout << quied::Same::none_of(Vec.begin(), Vec.end(), 5);

	std::cout << quied::wless::getStockPage("$tsla");
}