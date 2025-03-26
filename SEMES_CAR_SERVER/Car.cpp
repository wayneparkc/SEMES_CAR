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

void Car::setBreak(int breaksys) {
	if (breaksys == 1) this->bs = BreakSystem::MANDO;
	else if (breaksys == 2) this->bs = BreakSystem::CONTINENTAL;
	else if (breaksys == 3) this->bs = BreakSystem::BOSCH_B;
}

void Car::setSteering(int steeringsys) {
	if (steeringsys == 1) this->steer = SteeringSystem::BOSCH_S;
	else if (steeringsys == 2) this->steer = SteeringSystem::MOBIS;
}

void Car::checkSteer() {
	if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer || BreakSystem::BOSCH_B != bs && SteeringSystem::BOSCH_S == steer) {
		// 에러 발생
		throw different_brand_error("BOSCH 제동장치는 BOSCH 조향장치만 호환됩니다.");
	}
}

std::unique_ptr<Car> Factor(int type) {
	if (type == 1)
		return std::make_unique<Sedan>();
	else if (type == 2)
		return std::make_unique<SUV>();
	else if (type == 3)
		return std::make_unique<Truck>();
	return nullptr;
}