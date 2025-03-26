#include "Car.h"
#include "SUV.h"
#include "Sedan.h"
#include "Truck.h"
#include <memory>

void Car::setEngine(int engine) {
	if (engine == 1) this->engine = Engine::GM;
	else if (engine == 2) this->engine = Engine::TOYOTA;
	else if (engine == 3) this->engine = Engine::WIA;
}

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

void Car::setSteering(int steeringsys) {
	if (steeringsys == 1) this->steer = SteeringSystem::BOSCH_S;
	else if (steeringsys == 2) this->steer = SteeringSystem::MOBIS;
}

std::string Car::getEngine() {
	if (static_cast<int>(this->engine) == 1) return "GM";
	else if (static_cast<int>(this->engine) == 2) return "TOYOTA";
	else if (static_cast<int>(this->engine) == 3) return "WIA";
}

std::string Car::getBreak() {
	if (static_cast<int>(this->bs) == 1) return "MANDO";
	else if (static_cast<int>(this->bs) == 2) return "CONTINENTAL";
	else if (static_cast<int>(this->bs) == 3) return "BOSCH_B";
}

std::string Car::getSteering() {
	if (static_cast<int>(this->steer) == 1) return "BOSCH_S";
	else if (static_cast<int>(this->steer) == 2) return "MOBIS";
}

void Car::checkSteer() {
	if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer || BreakSystem::BOSCH_B != bs && SteeringSystem::BOSCH_S == steer) {
		// 에러 발생
		throw different_brand_error("BOSCH 제동장치는 BOSCH 조향장치만 호환됩니다.");
	}
}
void Car::run() {
	if (this->engine == Engine::GM || this->engine == Engine::TOYOTA || this->engine == Engine::WIA) {
		std::cout << "자동차가 동작됩니다.\n";
	}
	else {
		std::cout << "엔진이 고장났습니다.\n";
	}
	printf("동작 정지 [Enter]");
	std::cin.ignore();
	std::cin.get();
}
Car::Car() {
	car_step = {
		{2, [this](int v) {this->setEngine(v); }},
		{3, [this](int v) {this->setBreak(v); }},
		{4, [this](int v) {this->setSteering(v); }},
		{5, [this](int v) {
			if (v == 1) this->run();
			else if (v == 2) this->info();
			else this->test();
		}},
	};
}

std::unique_ptr<Car> Factor(int type) {
	if (type == 1)
		return std::make_unique<Sedan>();
	else if (type == 2)
		return std::make_unique<SUV>();
	return std::make_unique<Truck>();
}