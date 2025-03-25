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
	//Enum Class Type�� 1���� ����.
	Engine engine; 
	BreakSystem bs;
	SteeringSystem steer;

	void checkSteer() {
		if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer) {
			// ���� �߻�
			throw different_brand_error("BOSCH ������ġ�� BOSCH ������ġ�� ȣȯ�˴ϴ�.");
		}
	}
	virtual void test() = 0;
};

class Sedan : public Car {
private:
	void checkBreak() {
		if (BreakSystem::CONTINENTAL == bs) {
			// ���� �߻�
			throw not_make_break("CONTINENTAL ��� ������ ������ġ�� ������ �ʽ��ϴ�.");
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
			throw not_make_engine("����Ÿ�� SUV�� ������ ������ �ʽ��ϴ�.");
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
			throw not_make_engine("WIA�� Truck�� ������ ������ �ʽ��ϴ�.");
		}
	}
	void checkBreakSystem() {
		if (BreakSystem::MANDO == bs) {
			// ���� �߻�
			throw not_make_break(" Mando�� Truck�� ������ġ�� ������ �ʽ��ϴ�.");
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