#include "Truck.h"
void Truck::checkEngine() {
	if (Engine::WIA == engine) {
		// 에러 발생
		throw not_make_engine("WIA는 Truck용 엔진을 만들지 않습니다.");
	}
}
void Truck::checkBreakSystem() {
	if (BreakSystem::MANDO == bs) {
		// 에러 발생
		throw not_make_break(" Mando는 Truck용 제동장치를 만들지 않습니다.");
	}
}
void Truck::test() {
	checkSteer();
	checkEngine();
	checkBreakSystem();
}
void Truck::info() {
	printf("     _________\n");
	printf("   /|         |\n");
	printf("  /_|_________|__________________\n");
	printf(" |                            o  |\n");
	printf(" '-(@)----------------------(@)--'\n");
	printf("===============================\n");
	printf("제조된 자동차 정보\n");
	printf("차량 타입 : Truck\n");
	std::cout << "엔     진 : " << this->getEngine() << "\n";
	std::cout << "제동 장치 : " << this->getBreak() << "\n";
	std::cout << "조향 장치 : " << this->getSteering() << "\n";
	printf("===============================\n");
	printf("정보 닫기 [Enter]");
	std::cin.ignore();
	std::cin.get();
}