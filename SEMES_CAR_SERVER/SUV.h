#pragma once
#include "Car.h"
class SUV : public Car {
private:
	void checkEngine();

public:
	// Car��(��) ���� ��ӵ�
	std::string test();
};