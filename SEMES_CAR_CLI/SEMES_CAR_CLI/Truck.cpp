#include "Truck.h"

void Truck::info() {
	printf("     _________\n");
	printf("   /|         |\n");
	printf("  /_|_________|__________________\n");
	printf(" |                            o  |\n");
	printf(" '-(@)----------------------(@)--'\n");
	printf("===============================\n");
	printf("������ �ڵ��� ����\n");
	printf("���� Ÿ�� : Truck\n");
	std::cout << "��     �� : " << this->getEngine() << "\n";
	std::cout << "���� ��ġ : " << this->getBreak() << "\n";
	std::cout << "���� ��ġ : " << this->getSteering() << "\n";
	printf("===============================\n");
	printf("���� �ݱ� [Enter]");
	std::cin.ignore();
	std::cin.get();
}

int Truck::typeof()
{
	return 3;
}
