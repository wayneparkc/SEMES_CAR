#include "Sedan.h"

void Sedan::checkBreak() {
	if (BreakSystem::CONTINENTAL == bs) {
		// 에러 발생
		throw not_make_break("CONTINENTAL 사는 세단의 제동장치를 만들지 않습니다.");
	}
}
// Car을(를) 통해 상속됨
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
	message += errmsg.empty() ? "차량이 정상적으로 조립되었습니다." : errmsg;
	return message;
}

