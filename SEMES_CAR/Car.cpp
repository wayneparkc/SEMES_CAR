#include "Car.h"
#include <memory>

// different_brand_error ������ ����
different_brand_error::different_brand_error(const char* msg) : std::exception(msg) {}

// Car Ŭ������ checkSteer() �Լ� ����
void Car::checkSteer() {
    if (BreakSystem::BOSCH_B == bs && SteeringSystem::BOSCH_S != steer) {
        throw different_brand_error("BOSCH ������ġ�� BOSCH ������ġ�� ȣȯ�˴ϴ�.");
    }
}

// Sedan Ŭ������ checkBreak() �� test() �Լ� ����
void Sedan::checkBreak() {
    if (BreakSystem::CONTINENTAL == bs) {
        // ���� �߻�
    }
}

void Sedan::test() {
    checkSteer();
    checkBreak();
}

// SUV Ŭ������ checkEngine() �� test() �Լ� ����
void SUV::checkEngine() {
    if (Engine::TOYOTA == engine) {
        // ���� �߻�
    }
}

void SUV::test() {
    checkSteer();
    checkEngine();
}

// Truck Ŭ������ checkEngine(), checkBreakSystem() �� test() �Լ� ����
void Truck::checkEngine() {
    if (Engine::WIA == engine) {
        // ���� �߻�
    }
}

void Truck::checkBreakSystem() {
    if (BreakSystem::MANDO == bs) {
        // ���� �߻�
    }
}

void Truck::test() {
    checkSteer();
    checkEngine();
    checkBreakSystem();
}

// Factory �Լ� ����
std::unique_ptr<Car> Factor(std::string name) {
    if (name == "Sedan")
        return std::make_unique<Sedan>();
    else if (name == "SUV")
        return std::make_unique<SUV>();
    return std::make_unique<Truck>();
}
