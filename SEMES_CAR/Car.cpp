#include <iostream>
#include <string>
#include <unordered_map>
#include "part.h"

class Car {
public:
	virtual void Test() = 0;
};

class Sedan : public Car {
	void Test() override {

	}
};

class SUV : public Car {
	void Test() override {

	}
};

class Truck : public Car {
	void Test() override {

	}
};

std::shared_ptr<Car> Factor(std::string name) {
	if(name == "Sedan")
		return std::make_shared<Sedan>();
	else if (name == "SUV")
		return std::make_shared<SUV>();
	return std::make_shared<Truck>();
}