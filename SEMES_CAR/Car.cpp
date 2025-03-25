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
	//Enum Class Type는 1부터 시작.
	Engine engine; 
	BreakSystem bs;
	SteeringSystem steer;

	void setEngine(int engine) {
		if (engine == 1) this->engine = Engine::GM;
		else if (engine == 2) this->engine = Engine::TOYOTA;
		else if (engine == 3) this->engine = Engine::WIA;
	}

	void setBreak(int breaksys) {
		if (breaksys == 1) this->bs = BreakSystem::MANDO;
		else if (breaksys == 2) this->bs = BreakSystem::CONTINENTAL;
		else if (breaksys == 3) this->bs = BreakSystem::BOSCH_B;
	}

	void setSteering(int steeringsys) {
		if (steeringsys == 1) this->steer = SteeringSystem::BOSCH_S;
		else if (steeringsys == 2) this->steer = SteeringSystem::MOBIS;
	}

	std::string getEngine() {
		if (static_cast<int>(this->engine) == 1) return "GM";
		else if (static_cast<int>(this->engine) == 2) return "TOYOTA";
		else if (static_cast<int>(this->engine) == 3) return "WIA";
		return "";
	}

	std::string getBreak() {
		if (static_cast<int>(this->bs) == 1) return "MANDO";
		else if (static_cast<int>(this->bs) == 2) return "CONTINENTAL";
		else if (static_cast<int>(this->bs) == 3) return "BOSCH_B";
	}

	std::string getSteering() {
		if (static_cast<int>(this->steer) == 1) return "BOSCH_S";
		else if (static_cast<int>(this->steer) == 2) return "MOBIS";
	}

	void checkSteer() {
		if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer) {
			// 에러 발생
			throw different_brand_error("BOSCH 제동장치는 BOSCH 조향장치와 호환됩니다.");
		}
	}

	void run() {
		if (this->engine == Engine::GM || this->engine == Engine::TOYOTA || this->engine == Engine::WIA) {
			std::cout << "자동차가 동작됩니다.\n";
		}
		else {
			std::cout << "엔진이 고장났습니다.\n";
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
		printf("어떤 차량 타입을 선택할까요?\n");
		printf("1. Sedan\n");
		printf("2. SUV\n");
		printf("3. Truck\n");
		printf("4. 종료\n");
		printf("===============================\n");
		return input();
	}

	int choose_engine() {
		printf(CLEAR_SCREEN);
		printf("어떤 엔진을 탑재할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. GM\n");
		printf("2. TOYOTA\n");
		printf("3. WIA\n");
		printf("4. 고장난 엔진\n");
		printf("===============================\n");
		return input();
	}

	int choose_break() {
		printf(CLEAR_SCREEN);
		printf("어떤 제동장치를 선택할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. MANDO\n");
		printf("2. CONTINENTAL\n");
		printf("3. BOSCH\n");
		printf("===============================\n");
		return input();
	}

	int choose_steering() {
		printf(CLEAR_SCREEN);
		printf("어떤 조향장치를 선택할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. BOSCH\n");
		printf("2. MOBIS\n");
		printf("===============================\n");
		return input();
	}

	int choose_action() {
		printf(CLEAR_SCREEN);
		printf("멋진 차량이 완성되었습니다.\n");
		printf("어떤 동작을 할까요?\n");
		printf("0. 처음 화면으로 돌아가기\n");
		printf("1. RUN\n");
		printf("2. Info\n");
		printf("3. Test\n");
		printf("===============================\n");
		return input();
	}

	void info(Car& car) {
		printf(CLEAR_SCREEN);
		if (auto sedan = dynamic_cast<const Sedan*>(&car)) {
			printf("        _________\n");
			printf("       /|        |\n");
			printf("  ____/_|________|______\n");
			printf(" |                    o |\n");
			printf(" '-(@)------------(@)--'\n");
			printf("===============================\n");
			printf("제조된 자동차 정보\n");
			printf("차량 타입 : Sedan\n");
		}
		else if (auto suv = dynamic_cast<const SUV*>(&car)) {
			printf("        _______________\n");
			printf("       /|              |\n");
			printf("  ____/_|______________|_____\n");
			printf(" |                        o  |\n");
			printf(" '-(@)------------------(@)--'\n");
			printf("===============================\n");
			printf("제조된 자동차 정보\n");
			printf("차량 타입 : Suv\n");
		}
		else if (auto truck = dynamic_cast<const Truck*>(&car)) {
			printf("     _________\n");
			printf("   /|         |\n");
			printf("  /_|_________|__________________\n");
			printf(" |                            o  |\n");
			printf(" '-(@)----------------------(@)--'\n");
			printf("===============================\n");
			printf("제조된 자동차 정보\n");
			printf("차량 타입 : Truck\n");
		}
		std::cout << "엔     진 : " << car.getEngine() << "\n";
		std::cout << "제동 장치 : " << car.getBreak() << "\n";
		std::cout << "조향 장치 : " << car.getSteering() << "\n";
		printf("===============================\n");
		printf("정보 닫기 ");
	}

};

int main() {

	std::unique_ptr<Car> car;
	Console console;

	while (1) {

		if (console.get_step() == 1) {
			int type = console.choose_type();
			car = Factor(type);
			// 차량 타입이 1, 2, 3이 아니면 종료
			if (!(type>=1 && type<=3)) break;
		}
		else if (console.get_step() == 2) {
			int engine = console.choose_engine();
			car->setEngine(engine);
		}
		else if (console.get_step() == 3) {
			int breaksys = console.choose_break();
			car->setBreak(breaksys);
		}
		else if (console.get_step() == 4) {
			int steeringsys = console.choose_steering();
			car->setSteering(steeringsys);
		}
		else if (console.get_step() == 5) {
			int action = console.choose_action();
			if (action == 1) car->run();
			else if (action == 2) console.info(*car);
			else if (action == 3) car->test();
		}
	}
}