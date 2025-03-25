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
		printf("� ���� Ÿ���� �����ұ��?\n");
		printf("1. Sedan\n");
		printf("2. SUV\n");
		printf("3. Truck\n");
		printf("4. ����\n");
		printf("===============================\n");
		return input();
	}

	int Console::choose_engine() {
		printf(CLEAR_SCREEN);
		printf("� ������ ž���ұ��?\n");
		printf("0. �ڷΰ���\n");
		printf("1. GM\n");
		printf("2. TOYOTA\n");
		printf("3. WIA\n");
		//printf("4. ���峭 ����\n");
		printf("===============================\n");
		return input();
	}

	int Console::choose_break() {
		printf(CLEAR_SCREEN);
		printf("� ������ġ�� �����ұ��?\n");
		printf("0. �ڷΰ���\n");
		printf("1. MANDO\n");
		printf("2. CONTINENTAL\n");
		printf("3. BOSCH\n");
		printf("===============================\n");
		return input();
	}

	int Console::choose_steering() {
		printf(CLEAR_SCREEN);
		printf("� ������ġ�� �����ұ��?\n");
		printf("0. �ڷΰ���\n");
		printf("1. BOSCH\n");
		printf("2. MOBIS\n");
		printf("===============================\n");
		return input();
	}

	int Console::choose_action() {
		printf(CLEAR_SCREEN);
		printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
		printf("� ������ �ұ��?\n");
		printf("0. ó�� ȭ������ ���ư���\n");
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
