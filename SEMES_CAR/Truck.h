#pragma once
#include "Car.h"
class Truck : public Car {
private:
	void checkEngine();
	void checkBreakSystem();

public:
	// Car��(��) ���� ��ӵ�
	void test();
	void info();
};