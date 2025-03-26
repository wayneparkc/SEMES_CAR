#pragma once
#include "Car.h"
class Sedan : public Car {
private:
	void checkBreak();
public:
	// Car을(를) 통해 상속됨
	std::string test();
};