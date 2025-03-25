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

	//Enum Class Type�� 1���� ����.
	virtual void test() = 0;

	void Set(Engine _engine, BreakSystem _bs, SteeringSystem _steer) {
		this->engine = _engine;
		this->bs = _bs;
		this->steer = _steer;
	}

	void checkSteer() {
		if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer) {
			// ���� �߻�
			throw different_brand_error("BOSCH ������ġ�� BOSCH ������ġ�� ȣȯ�˴ϴ�.");
		}
	}
};

class Sedan : public Car {
private:
	void checkBreak() {
		if (BreakSystem::CONTINENTAL == bs) {
			// ���� �߻�

		}
	}

public:
	// Car��(��) ���� ��ӵ�
	void test() override {
		checkSteer();
		checkBreak();
	}
};

class SUV : public Car {
private:
	void checkEngine() {
		if (Engine::TOYOTA == engine) {
			// ���� �߻�

		}
	}

public:
	// Car��(��) ���� ��ӵ�
	void test() override {
		checkSteer();
		checkEngine();
	}
};

class Truck : public Car {
private:
	void checkEngine() {
		if (Engine::WIA == engine) {
			// ���� �߻�

		}
	}
	void checkBreakSystem() {
		if (BreakSystem::MANDO == bs) {
			// ���� �߻�

		}
	}

public:
	// Car��(��) ���� ��ӵ�
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