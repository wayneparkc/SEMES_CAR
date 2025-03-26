#include "SUV.h"

void SUV::checkEngine() {
	if (Engine::TOYOTA == engine) {
		// 에러 발생
		throw not_make_engine("toyota do not make the engine for SUV");
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
	message += errmsg.empty() ? "SUV Complete" : errmsg;
	return message;
}