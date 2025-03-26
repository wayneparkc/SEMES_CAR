#pragma once
#include "Car.h"
class SUV : public Car {
private:
	void checkEngine();

public:
	// Car을(를) 통해 상속됨
	std::string test();
};