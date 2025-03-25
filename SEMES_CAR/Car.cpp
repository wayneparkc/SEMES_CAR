#include <iostream>
#include <string>
#include <unordered_map>
#include "part.h"
#define interface struct

class different_brand_error : public std::exception {
public:
	different_brand_error(const char* msg) : exception{ msg } {};
};

interface Car{

	Engine engine;
	BreakSystem bs;
	SteeringSystem steer;

	//Enum Class Type는 1부터 시작.
	virtual void test() = 0;

	void Set(Engine _engine, BreakSystem _bs, SteeringSystem _steer) {
		this->engine = _engine;
		this->bs = _bs;
		this->steer = _steer;
	}

	void checkSteer() {
		if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer) {
			// 에러 발생
			throw different_brand_error("BOSCH 제동장치는 BOSCH 조향장치와 호환됩니다.");
		}
	}
};

class Sedan : public Car {
private:
	void checkBreak() {
		if (BreakSystem::CONTINENTAL == bs) {
			// 에러 발생

		}
	}

public:
	// Car을(를) 통해 상속됨
	void test() override {
		checkSteer();
		checkBreak();
	}
};

class SUV : public Car {
private:
	void checkEngine() {
		if (Engine::TOYOTA == engine) {
			// 에러 발생

		}
	}

public:
	// Car을(를) 통해 상속됨
	void test() override {
		checkSteer();
		checkEngine();
	}
};

class Truck : public Car {
private:
	void checkEngine() {
		if (Engine::WIA == engine) {
			// 에러 발생

		}
	}
	void checkBreakSystem() {
		if (BreakSystem::MANDO == bs) {
			// 에러 발생

		}
	}

public:
	// Car을(를) 통해 상속됨
	void test() override {
		checkSteer();
		checkEngine();
		checkBreakSystem();
	}
};
std::unique_ptr<Car> Factor(std::string name) {
	if(name == "Sedan")
		return std::make_unique<Sedan>();
	else if (name == "SUV")
		return std::make_unique<SUV>();
	return std::make_unique<Truck>();
}