#include "Car.h"
#include <memory>

// different_brand_error 생성자 구현
different_brand_error::different_brand_error(const char* msg) : std::exception(msg) {}

// Car 클래스의 checkSteer() 함수 구현
void Car::checkSteer() {
    if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer) {
        throw different_brand_error("BOSCH 제동장치는 BOSCH 조향장치와 호환됩니다.");
    }
}

// Sedan 클래스의 checkBreak() 및 test() 함수 구현
void Sedan::checkBreak() {
    if (BreakSystem::CONTINENTAL == bs) {
        // 에러 발생
    }
}

void Sedan::test() {
    checkSteer();
    checkBreak();
}

// SUV 클래스의 checkEngine() 및 test() 함수 구현
void SUV::checkEngine() {
    if (Engine::TOYOTA == engine) {
        // 에러 발생
    }
}

void SUV::test() {
    checkSteer();
    checkEngine();
}

// Truck 클래스의 checkEngine(), checkBreakSystem() 및 test() 함수 구현
void Truck::checkEngine() {
    if (Engine::WIA == engine) {
        // 에러 발생
    }
}

void Truck::checkBreakSystem() {
    if (BreakSystem::MANDO == bs) {
        // 에러 발생
    }
}

void Truck::test() {
    checkSteer();
    checkEngine();
    checkBreakSystem();
}

// Factory 함수 구현
std::unique_ptr<Car> Factor(std::string name) {
    if (name == "Sedan")
        return std::make_unique<Sedan>();
    else if (name == "SUV")
        return std::make_unique<SUV>();
    return std::make_unique<Truck>();
}
