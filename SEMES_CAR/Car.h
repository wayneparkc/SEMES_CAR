#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "part.h"

#define interface struct

class different_brand_error : public std::exception {
public:
	different_brand_error(const char* msg);
};

interface Car{
	//Enum Class Type는 1부터 시작.
	Engine engine;
	BreakSystem bs;
	SteeringSystem steer;

	void checkSteer();
	virtual void test() = 0;
};

class Sedan : public Car {
private:
	void checkBreak();

public:
	// Car을(를) 통해 상속됨
	void test();
};

class SUV : public Car {
private:
	void checkEngine();

public:
	// Car을(를) 통해 상속됨
	void test();
};

class Truck : public Car {
private:
	void checkEngine();
	void checkBreakSystem();

public:
	// Car을(를) 통해 상속됨
	void test();
};
std::unique_ptr<Car> Factor(std::string name);