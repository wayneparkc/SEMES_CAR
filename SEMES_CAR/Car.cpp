#include <iostream>
#include <string>
#include <unordered_map>
#include "part.h"

#define interface struct
#define CLEAR_SCREEN "\033[H\033[2J"

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

	void setEngine(Engine _engine) {
		this->engine = _engine;
	}

	void setBreak(BreakSystem _bs) {
		this->bs = _bs;
	}

	void setSteering(SteeringSystem _steer) {
		this->steer = _steer;
	}

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
std::unique_ptr<Car> Factor(int type) {
	if(type == 1)
		return std::make_unique<Sedan>();
	else if (type == 2)
		return std::make_unique<SUV>();
	else if(type == 3)
		return std::make_unique<Truck>();
	return std::make_unique<Car>();
}

class Console {
	int step = 1;

public:
	int get_step() {
		return step;
	}

	int input() {
		printf("INPUT > ");
		int num;
		std::cin >> num;
		return num;
	}

	int choose_type() {
		printf(CLEAR_SCREEN);
		printf("        ______________\n");
		printf("       /|            | \n");
		printf("  ____/_|_____________|____\n");
		printf(" |                      O  |\n");
		printf(" '-(@)----------------(@)--'\n");
		printf("===============================\n");
		printf("� ���� Ÿ���� �����ұ��?\n");
		printf("1. Sedan\n");
		printf("2. SUV\n");
		printf("3. Truck\n");
		printf("4. ����\n");
		printf("===============================\n");
		return input();
	}

	int choose_engine() {
		printf(CLEAR_SCREEN);
		printf("� ������ ž���ұ��?\n");
		printf("0. �ڷΰ���\n");
		printf("1. GM\n");
		printf("2. TOYOTA\n");
		printf("3. WIA\n");
		printf("4. ���峭 ����\n");
		printf("===============================\n");
		return input();
	}

	int choose_break() {
		printf(CLEAR_SCREEN);
		printf("� ������ġ�� �����ұ��?\n");
		printf("0. �ڷΰ���\n");
		printf("1. MANDO\n");
		printf("2. CONTINENTAL\n");
		printf("3. BOSCH\n");
		printf("===============================\n");
		return input();
	}

	int choose_steering() {
		printf(CLEAR_SCREEN);
		printf("� ������ġ�� �����ұ��?\n");
		printf("0. �ڷΰ���\n");
		printf("1. BOSCH\n");
		printf("2. MOBIS\n");
		printf("===============================\n");
		return input();
	}

	int choose_action() {
		printf(CLEAR_SCREEN);
		printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
		printf("� ������ �ұ��?\n");
		printf("0. ó�� ȭ������ ���ư���\n");
		printf("1. RUN\n");
		printf("2. Info\n");
		printf("3. Test\n");
		printf("===============================\n");
		return input();
	}

};

int main() {

	std::unique_ptr<Car> car;
	Console console;

	while (1) {

		if (console.get_step() == 1) {
			int type = console.choose_type();
			car = Factor(type);
			// ���� Ÿ���� 1, 2, 3�� �ƴϸ� ����
			if (!(type>=1 && type<=3)) break;
		}
		else if (console.get_step() == 2) {
			int engine = console.choose_engine();
			
		}
		else if (console.get_step() == 3) {

		}
		else if (console.get_step() == 4) {

		}
		else if (console.get_step() == 5) {

		}
	}
}