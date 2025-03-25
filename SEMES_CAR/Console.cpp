#pragma once
#include "Console.h"
#include "functional"
#include <iostream>
#define CLEAR_SCREEN "\033[H\033[2J"

	int Console::get_step() {
		return step;
	}

	int Console:: input() {
		printf("INPUT > ");
		int num;
		std::cin >> num;
		return num;
	}

	int Console::choose_type() {
		printf(CLEAR_SCREEN);
		printf("        ______________\n");
		printf("       /|            | \n");
		printf("  ____/_|_____________|____\n");
		printf(" |                      O  |\n");
		printf(" '-(@)----------------(@)--'\n");
		printf("===============================\n");
		printf("어떤 차량 타입을 선택할까요?\n");
		printf("1. Sedan\n");
		printf("2. SUV\n");
		printf("3. Truck\n");
		printf("4. 종료\n");
		printf("===============================\n");
		return input();
	}

	int Console::choose_engine() {
		printf(CLEAR_SCREEN);
		printf("어떤 엔진을 탑재할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. GM\n");
		printf("2. TOYOTA\n");
		printf("3. WIA\n");
		//printf("4. 고장난 엔진\n");
		printf("===============================\n");
		return input();
	}

	int Console::choose_break() {
		printf(CLEAR_SCREEN);
		printf("어떤 제동장치를 선택할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. MANDO\n");
		printf("2. CONTINENTAL\n");
		printf("3. BOSCH\n");
		printf("===============================\n");
		return input();
	}

	int Console::choose_steering() {
		printf(CLEAR_SCREEN);
		printf("어떤 조향장치를 선택할까요?\n");
		printf("0. 뒤로가기\n");
		printf("1. BOSCH\n");
		printf("2. MOBIS\n");
		printf("===============================\n");
		return input();
	}

	int Console::choose_action() {
		printf(CLEAR_SCREEN);
		printf("멋진 차량이 완성되었습니다.\n");
		printf("어떤 동작을 할까요?\n");
		printf("0. 처음 화면으로 돌아가기\n");
		printf("1. RUN\n");
		printf("2. Info\n");
		printf("3. Test\n");
		printf("===============================\n");
		return input();
	}
	void Console::set_step(int input) {
		if (input == 0 && this->step == 5) {
			this->step = 1;
		}
		else if (input == 0 && this->step >= 1) {
			this->step -= 1;
		}
		else if (this->step <= 4) {
			this->step += 1;
		}
	}
	Console::Console() {
		step = 1;
		console_step = {
			{1, std::bind(&Console::choose_type, this)},
			{2, std::bind(&Console::choose_engine, this)},
			{3, std::bind(&Console::choose_break, this)},
			{4, std::bind(&Console::choose_steering, this)},
			{5, std::bind(&Console::choose_action, this)}
		};
	}
