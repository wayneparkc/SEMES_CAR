#include "SUV.h"

void SUV::checkEngine() {
	if (Engine::TOYOTA == engine) {
		// ���� �߻�
		throw not_make_engine("����Ÿ�� SUV�� ������ ������ �ʽ��ϴ�.");
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
	printf("������ �ڵ��� ����\n");
	printf("���� Ÿ�� : Suv\n");
	std::cout << "��     �� : " << this->getEngine() << "\n";
	std::cout << "���� ��ġ : " << this->getBreak() << "\n";
	std::cout << "���� ��ġ : " << this->getSteering() << "\n";
	printf("===============================\n");
	printf("���� �ݱ� [Enter]");
	std::cin.ignore();
	std::cin.get();
}