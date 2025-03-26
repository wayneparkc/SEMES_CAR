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
					std::cout << "�������� �ʴ� ���� Ÿ���Դϴ�.";
					break;
				}
			}
		}
		console.set_step(result);
	}
	std::cout << "���� ����������Ʈ�� �����մϴ�.";
	return 0;
}