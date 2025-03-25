#pragma once
#include "Car.h"
class Truck : public Car {
private:
	void checkEngine();
	void checkBreakSystem();

public:
	// Car을(를) 통해 상속됨
	void test();
	void info();
};