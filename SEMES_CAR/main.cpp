#include "Car.h"
#include "Console.h"

int main() {
	std::unique_ptr<Car> car;
	Console console;

	while (1) {

		if (console.get_step() == 1) {
			int type = console.choose_type();
			car = Factor(type);
			// 차량 타입이 1, 2, 3이 아니면 종료
			if (!(type >= 1 && type <= 3)) break;
		}
		else if (console.get_step() == 2) {
			int engine = console.choose_engine();
			car->setEngine(engine);
		}
		else if (console.get_step() == 3) {
			int breaksys = console.choose_break();
			car->setBreak(breaksys);
		}
		else if (console.get_step() == 4) {
			int steeringsys = console.choose_steering();
			car->setSteering(steeringsys);
		}
		else if (console.get_step() == 5) {
			int action = console.choose_action();
			if (action == 1) car->run();
			else if (action == 2) car->info();
			else if (action == 3) car->test();
		}
		console.set_step(console.get_step());
	}
	return 0;
}