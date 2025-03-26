#include "SUV.h"

void SUV::checkEngine() {
	if (Engine::TOYOTA == engine) {
		// ���� �߻�
		throw not_make_engine("����Ÿ�� SUV�� ������ ������ �ʽ��ϴ�.");
	}
}

std::string SUV::test() {
	bool flag = true;
	std::string errmsg = "";

	try {
		checkSteer();
		checkEngine();
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