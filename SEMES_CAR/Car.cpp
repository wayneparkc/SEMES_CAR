#include <iostream>
#include <string>
#include <unordered_map>
#include "part.h"

#define interface struct

class different_brand_error : public std::exception {
public:
	different_brand_error(const char* msg) : exception{ msg } {};
};

class not_make_break : public std::exception {
public:
	not_make_break(const char* msg) : exception{ msg } {};
};

class not_make_engine : public std::exception {
public:
	not_make_engine(const char* msg) : exception{ msg } {};
};

interface Car{
	//Enum Class Type는 1부터 시작.
	Engine engine; 
	BreakSystem bs;
	SteeringSystem steer;

	void checkSteer() {
		if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer) {
			// 에러 발생
			throw different_brand_error("BOSCH 제동장치는 BOSCH 조향장치와 호환됩니다.");
		}
	}
	virtual void test() = 0;
};

class Sedan : public Car {
private:
	void checkBreak() {
		if (BreakSystem::CONTINENTAL == bs) {
			// 에러 발생
			throw not_make_break("CONTINENTAL 사는 세단의 제동장치를 만들지 않습니다.");
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
			throw not_make_engine("도요타는 SUV용 엔진을 만들지 않습니다.");
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
			throw not_make_engine("WIA는 Truck용 엔진을 만들지 않습니다.");
		}
	}
	void checkBreakSystem() {
		if (BreakSystem::MANDO == bs) {
			// 에러 발생
			throw not_make_break(" Mando는 Truck용 제동장치를 만들지 않습니다.");
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