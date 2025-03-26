#include "Sedan.h"

void Sedan::checkBreak() {
	if (BreakSystem::CONTINENTAL == bs) {
		// ���� �߻�
		throw not_make_break("CONTINENTAL ��� ������ ������ġ�� ������ �ʽ��ϴ�.");
	}
}
// Car��(��) ���� ��ӵ�
void Sedan::test() {
	bool flag = true;
	try {
		checkSteer();
		checkBreak();
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


