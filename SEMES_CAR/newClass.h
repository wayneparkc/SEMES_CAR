#include<string>
#define interface struct

enum Engine {
	GM = 1,
	TOYOTA = 2,
	WIA = 3
};

enum BreakSystem {
	MANDO = 1,
	CONTINENTAL = 2,
	BOSCH_B = 3
};

enum SteeringSystem {
	BOSCH_S = 1,
	MOBIS = 2
};

class different_brand_error : public std::exception {
public:
	different_brand_error(const char* msg) : exception{ msg } {};
};


interface Car{
	Engine engine;
	BreakSystem bs;
	SteeringSystem steer;

	void checkSteer() {
		if (BreakSystem(BOSCH_B) == bs && SteeringSystem(BOSCH_S) != steer) {
			// ���� �߻�
			throw different_brand_error("BOSCH ������ġ�� BOSCH ������ġ�� ȣȯ�˴ϴ�.");
		}
	}
	virtual void test()=0;
};

class Sedan : public Car {
private :
	void checkBreak() {
		if (BreakSystem(CONTINENTAL) == bs) {
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
private : 
	void checkEngine() {
		if (Engine(TOYOTA) == engine) {
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
private : 
	void checkEngine() {
		if (Engine(WIA) == engine) {
			// ���� �߻�

		}
	}
	void checkBreakSystem() {
		if (BreakSystem(MANDO) == bs) {
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