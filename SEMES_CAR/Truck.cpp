#include "Truck.h"
void Truck::checkEngine() {
	if (Engine::WIA == engine) {
		// ���� �߻�
		throw not_make_engine("WIA�� Truck�� ������ ������ �ʽ��ϴ�.");
	}
}
void Truck::checkBreakSystem() {
	try {
		if (BreakSystem::MANDO == bs) {
			// ���� �߻�
			throw not_make_break(" Mando�� Truck�� ������ġ�� ������ �ʽ��ϴ�.");
		}
	}
	catch (const not_make_break& e) {
		std::cerr << e.what() << std::endl;
		printf("===============================\n");
		printf("���� �ݱ� [Enter]");
	}
}
void Truck::test() {
	bool flag = true;
	try {
		checkSteer();
		checkEngine();
		checkBreakSystem();
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