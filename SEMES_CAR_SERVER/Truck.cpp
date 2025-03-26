#include "Truck.h"
void Truck::checkEngine() {
	if (Engine::WIA == engine) {
		// 에러 발생
		throw not_make_engine("WIA do not make the engine for Turck.");
	}
}
void Truck::checkBreakSystem() {
	try {
		if (BreakSystem::MANDO == bs) {
			// 에러 발생
			throw not_make_break("Mando do not make the steer for Turck.");
		}
	}
	catch (const not_make_break& e) {
		std::cerr << e.what() << std::endl;
		printf("===============================\n");
		printf("정보 닫기 [Enter]");
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
	message += errmsg.empty() ? "Truck Complete" : errmsg;
	return message;
}