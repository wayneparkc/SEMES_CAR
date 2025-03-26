#include "Truck.h"
void Truck::checkEngine() {
	if (Engine::WIA == engine) {
		// ���� �߻�
		throw not_make_engine("WIA�� Truck�� ������ ������ �ʽ��ϴ�.");
	}
}
void Truck::checkBreakSystem() {
	if (BreakSystem::MANDO == bs) {
		// ���� �߻�
		throw not_make_break(" Mando�� Truck�� ������ġ�� ������ �ʽ��ϴ�.");
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