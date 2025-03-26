#include "SUV.h"

void SUV::checkEngine() {
	if (Engine::TOYOTA == engine) {
		// ���� �߻�
		throw not_make_engine("����Ÿ�� SUV�� ������ ������ �ʽ��ϴ�.");
	}
}

void SUV::test() {
	bool flag = true;
	try {
		checkSteer();
		checkEngine();
	}
	catch (const not_make_break& e) {
		flag = false;
		std::cerr << e.what() << std::endl;
	}
	catch (const not_make_engine& e) {
		flag = false;
		std::cerr << e.what() << std::endl;
	}
	catch (const different_brand_error& e) {
		flag = false;
		std::cerr << e.what() << std::endl;
	}
	if (flag)
		std::cout << "�׽�Ʈ�� ���������� ������ �Ǿ����ϴ�.\n";
	else
		std::cout << "\n�� ������ ���� �ҷ��Դϴ�.\n";
	printf("===============================\n");
	printf("���� �ݱ� [Enter]");
	std::cin.ignore();
	std::cin.get();
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