#include "Sedan.h"

void Sedan::info() {
	printf("        _________\n");
	printf("       /|        |\n");
	printf("  ____/_|________|______\n");
	printf(" |                    o |\n");
	printf(" '-(@)------------(@)--'\n");
	printf("===============================\n");
	printf("제조된 자동차 정보\n");
	printf("차량 타입 : Sedan\n");
	std::cout << "엔     진 : " << this->getEngine() << "\n";
	std::cout << "제동 장치 : " << this->getBreak() << "\n";
	std::cout << "조향 장치 : " << this->getSteering() << "\n";
	printf("===============================\n");
	printf("정보 닫기 [Enter]");
	std::cin.ignore();
	std::cin.get();
}

int Sedan::typeof()
{
	return 1;
}


