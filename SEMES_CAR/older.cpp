#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "part.h"

#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];

void selectCarType(int answer);
void selectEngine(int answer);
void selectBreakSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void infoProducedCar();
// void testProducedCar();
void delay(int ms);

void delay(int ms) {
	volatile int sum = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			for (int t = 0; t < ms; t++) {
				sum++;
			}
		}
	}
}

void next() {
	char buf[100];
	printf("(Enter)");
	fgets(buf, sizeof(buf), stdin);
}

int main() {
	char buf[100];
	int step = static_cast<int>(QuestionType::CarType_Q);

	while (1) {

		if (step == 1) {
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
		}
		else if (step == 2) {
			printf(CLEAR_SCREEN);
			printf("� ������ ž���ұ��?\n");
			printf("0. �ڷΰ���\n");
			printf("1. GM\n");
			printf("2. TOYOTA\n");
			printf("3. WIA\n");
			printf("4. ���峭 ����\n");
		}
		else if (step == 3) {
			printf(CLEAR_SCREEN);
			printf("� ������ġ�� �����ұ��?\n");
			printf("0. �ڷΰ���\n");
			printf("1. MANDO\n");
			printf("2. CONTINENTAL\n");
			printf("3. BOSCH\n");
		}
		else if (step == 4) {
			printf(CLEAR_SCREEN);
			printf("� ������ġ�� �����ұ��?\n");
			printf("0. �ڷΰ���\n");
			printf("1. BOSCH\n");
			printf("2. MOBIS\n");
		}
		else if (step == 5) {
			printf(CLEAR_SCREEN);
			printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
			printf("� ������ �ұ��?\n");
			printf("0. ó�� ȭ������ ���ư���\n");
			printf("1. RUN\n");
			printf("2. Info\n");
			printf("3. Test\n");
		}
		printf("===============================\n");

		printf("INPUT > ");
		fgets(buf, sizeof(buf), stdin);

		//���� ���๮�� ����
		char* c = NULL;
		char* ch = strtok_s(buf, "\r", &c);
		ch = strtok_s(buf, "\n", &c);


		if (!strcmp(buf, "4")) {
			printf("���̹���\n");
			break;
		}

		//���ڷ� �� ������� Ȯ��
		char* checkNumber;
		int answer = strtol(buf, &checkNumber, 10); //���ڿ��� 10������ ��ȯ

		//�Է¹��� ���ڰ� ���ڰ� �ƴ϶��
		if (*checkNumber != '\0') {
			printf("ERROR :: ���ڸ� �Է� ����");
			next();
			continue;
		}

		if (step == 1 && !(answer >= 1 && answer <= 3)) {
			printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ���� ");
			next();
			continue;
		}

		if (step == 2 && !(answer >= 0 && answer <= 4)) {
			printf("ERROR :: ������ 1 ~ 4 ������ ���� ����");
			next();
			continue;
		}

		if (step == 3 && !(answer >= 0 && answer <= 3)) {
			printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����");
			next();
			continue;
		}

		if (step == 4 && !(answer >= 0 && answer <= 2)) {
			printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����");
			next();
			continue;
		}

		if (step == 5 && !(answer >= 0 && answer <= 3)) {
			printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�");
			next();
			continue;
		}

		//ó������ ���ư���
		if (answer == 0 && step == 5) {
			step = 1;
			continue;
		}

		//�������� ���ư���
		if (answer == 0 && step >= 1) {
			step -= 1;
			continue;
		}

		if (step == 1) {
			selectCarType(answer);
			delay(1500);
			step = 2;
		}
		else if (step == 2) {
			selectEngine(answer);
			delay(1500);
			step = 3;
		}
		else if (step == 3) {
			selectBreakSystem(answer);
			delay(1500);
			step = 4;
		}
		else if (step == 4) {
			selectSteeringSystem(answer);
			delay(1500);
			step = 5;
		}
		else if (step == 5 && answer == 1) {
			runProducedCar();
			next();
		}
		else if (step == 5 && answer == 2) {
			infoProducedCar();
			next();
		}
	}

}

void selectCarType(int answer) {
	stack[1] = answer;
	if (answer == 1) printf("���� Ÿ������ ������ �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("���� Ÿ������ TRUCK�� �����ϼ̽��ϴ�.\n");
}

void selectEngine(int answer) {
	stack[2] = answer;
	if (answer == 1) printf("GM ������ �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("WIA ������ �����ϼ̽��ϴ�.\n");
}

void selectBreakSystem(int answer) {
	stack[3] = answer;
	if (answer == 1) printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void selectSteeringSystem(int answer) {
	stack[4] = answer;
	if (answer == 1) printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
}

void runProducedCar() {
	if (stack[2] == 4) {
		printf("������ ���峵���ϴ�.\n");
		printf("�ڵ����� �������� �ʽ��ϴ�. ");
	}
	else {
		printf("�ڵ����� ���۵˴ϴ�. ");
	}
}

/*
void testProducedCar() {
	if (stack[1] == static_cast<int>(CarType::SEDAN) && stack[3] == static_cast<int>(CarType::CONTINENTAL)) {
		printf("�ڵ��� �׽�Ʈ ��� : FAIL\n");
		printf("Sedan�� Continental ������ġ�� �� �� �����ϴ� ");
	}
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA) {
		printf("�ڵ��� �׽�Ʈ ��� : FAIL\n");
		printf("SUV�� ����Ÿ ������ �� �� �����ϴ�. ");
	}
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA) {
		printf("�ڵ��� �׽�Ʈ ��� : FAIL\n");
		printf("Truck�� WIA ������ �� �� �����ϴ�. ");
	}
	else if (stack[CarType_Q] == TRUCK && stack[BreakSystem_Q] == MANDO) {
		printf("�ڵ��� �׽�Ʈ ��� : FAIL\n");
		printf("Truck�� MANDO ������ġ�� �� �� �����ϴ�. ");
	}
	else if (stack[BreakSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S) {
		printf("�ڵ��� �׽�Ʈ ��� : FAIL\n");
		printf("������ġ�� Bosch ��ǰ�� ��ٸ�, ������ġ�� Bosch ��ǰ�� ����մϴ�. ");
	}
	else if (stack[BreakSystem_Q] != BOSCH_B && stack[SteeringSystem_Q] == BOSCH_S) {
		printf("�ڵ��� �׽�Ʈ ��� : FAIL\n");
		printf("������ġ�� Bosch ��ǰ�� ��ٸ�, ������ġ�� Bosch ��ǰ�� ����մϴ�. ");
	}
	else {
		printf("�ڵ��� �׽�Ʈ ��� : PASS ");
	}

}
*/

void infoProducedCar() {
	printf(CLEAR_SCREEN);
	char car[] = "truck";
	if (strcmp(car, "sedan") == 0) {
		printf("        _________\n");
		printf("       /|        |\n");
		printf("  ____/_|________|______\n");
		printf(" |                    o |\n");
		printf(" '-(@)------------(@)--'\n");
	}
	else if (strcmp(car, "suv") == 0) {
		printf("        _______________\n");
		printf("       /|              |\n");
		printf("  ____/_|______________|_____\n");
		printf(" |                        o  |\n");
		printf(" '-(@)------------------(@)--'\n");
	}
	else if (strcmp(car, "truck") == 0) {
		printf("     _________\n");
		printf("   /|         |\n");
		printf("  /_|_________|__________________\n");
		printf(" |                            o  |\n");
		printf(" '-(@)----------------------(@)--'\n");

	}
	printf("===============================\n");
	printf("������ �ڵ��� ����\n");
	printf("���� Ÿ�� : ");
	printf("\n");
	printf("��     �� : ");
	printf("\n");
	printf("���� ��ġ : ");
	printf("\n");
	printf("���� ��ġ : ");
	printf("\n");
	printf("===============================\n");
	printf("���� �ݱ� ");
}