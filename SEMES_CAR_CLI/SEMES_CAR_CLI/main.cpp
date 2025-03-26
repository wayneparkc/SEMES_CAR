#include "Car.h"
#include "Console.h"


int main() {
	std::unique_ptr<Car> car;
	Console console;	

	while (console.get_flag()) {
		int step = console.get_step();
		int result = console.console_step[step]();
		if (result) {
			if (step == 1) car = Factor(result);
			else {
				if (car)
					car->car_step[step](result);
				else {
					std::cout << "존재하지 않는 차량 타입입니다.";
					break;
				}
			}
		}
		console.set_step(result);
	}
	std::cout << "차량 제작프로젝트를 종료합니다.";
	return 0;
}