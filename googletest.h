#pragma once

// #include "gtest/gtest.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "type_algorithms.h"

class AnyMock : public quied::any::Any {



};


TEST(Quied, Any) {

	int a = 5;
	quied::any::QAny any(55);

	 ASSERT_EQ(typeid(any.any_cast<int>(any)), typeid(a));
	
	
	
}