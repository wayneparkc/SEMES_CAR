#include "SUV.h"

void SUV::checkEngine() {
	if (Engine::TOYOTA == engine) {
		// 에러 발생
		throw not_make_engine("도요타는 SUV용 엔진을 만들지 않습니다.");
	}
}

void SUV::test() {
	checkSteer();
	checkEngine();
}

void SUV::info() {
	printf("        _______________\n");
	printf("       /|              |\n");
	printf("  ____/_|______________|_____\n");
	printf(" |                        o  |\n");
	printf(" '-(@)------------------(@)--'\n");
	printf("===============================\n");
	printf("제조된 자동차 정보\n");
	printf("차량 타입 : Suv\n");
	std::cout << "엔     진 : " << this->getEngine() << "\n";
	std::cout << "제동 장치 : " << this->getBreak() << "\n";
	std::cout << "조향 장치 : " << this->getSteering() << "\n";
	printf("===============================\n");
	printf("정보 닫기 [Enter]");
	std::cin.ignore();
	std::cin.get();
}