#pragma once
#include "Car.h"
class Sedan : public Car {
private:
	void checkBreak();
public:
	// Car��(��) ���� ��ӵ�
	std::string test();
};