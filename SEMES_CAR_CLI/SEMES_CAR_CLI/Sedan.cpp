#include "Sedan.h"

void Sedan::info() {
	printf("        _________\n");
	printf("       /|        |\n");
	printf("  ____/_|________|______\n");
	printf(" |                    o |\n");
	printf(" '-(@)------------(@)--'\n");
	printf("===============================\n");
	printf("������ �ڵ��� ����\n");
	printf("���� Ÿ�� : Sedan\n");
	std::cout << "��     �� : " << this->getEngine() << "\n";
	std::cout << "���� ��ġ : " << this->getBreak() << "\n";
	std::cout << "���� ��ġ : " << this->getSteering() << "\n";
	printf("===============================\n");
	printf("���� �ݱ� [Enter]");
	std::cin.ignore();
	std::cin.get();
}

int Sedan::typeof()
{
	return 1;
}


