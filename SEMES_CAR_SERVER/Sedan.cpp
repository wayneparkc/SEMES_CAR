#include "Sedan.h"

void Sedan::checkBreak() {
	if (BreakSystem::CONTINENTAL == bs) {
		// ���� �߻�
		throw not_make_break("CONTINENTAL do not make the break to Sedan.");
	}
}
// Car��(��) ���� ��ӵ�
std::string Sedan::test() {
	bool flag = true;
	std::string errmsg = "";
	try {
		checkSteer();
		checkBreak();
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
	message += errmsg.empty() ? "Sedan Complete" : errmsg;
	return message;
}

