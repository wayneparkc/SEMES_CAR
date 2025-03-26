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
std::string Truck::test() {
	bool flag = true;
	std::string errmsg = "";

	try {
		checkSteer();
		checkEngine();
		checkBreakSystem();
	}
	catch (const not_make_break& e) {
		flag = false;
		errmsg += e.what();
		std::cerr << e.what() << std::endl;
	}
	catch (const not_make_engine& e) {
		flag = false;
		errmsg += e.what();
		std::cerr << e.what() << std::endl;
	}
	catch (const different_brand_error& e) {
		flag = false;
		errmsg += e.what();
		std::cerr << e.what() << std::endl;
	}
	std::string message = flag ? "SU " : "FA ";
	message += errmsg.empty() ? "������ ���������� �����Ǿ����ϴ�." : errmsg;
	return message;
}