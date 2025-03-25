#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];

void selectCarType(int answer);
void selectEngine(int answer);
void selectBreakSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void infoProducedCar();
void testProducedCar();
void delay(int ms);

enum QuesionType {
	CarType_Q,
	Engine_Q,
	BreakSystem_Q,
	SteeringSystem_Q,
	Run_Test,
};

enum CarType {
	SEDAN = 1,
	SUV,
	TRUCK
};

enum Engine {
	GM = 1,
	TOYOTA,
	WIA
};

enum BreakSystem {
	MANDO = 1,
	CONTINENTAL,
	BOSCH_B
};

enum SteeringSystem {
	BOSCH_S = 1,
	MOBIS
};

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
	int step = CarType_Q;

	while (1) {

		if (step == CarType_Q) {
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
		else if (step == Engine_Q) {
			printf(CLEAR_SCREEN);
			printf("� ������ ž���ұ��?\n");
			printf("0. �ڷΰ���\n");
			printf("1. GM\n");
			printf("2. TOYOTA\n");
			printf("3. WIA\n");
			printf("4. ���峭 ����\n");
		}
		else if (step == BreakSystem_Q) {
			printf(CLEAR_SCREEN);
			printf("� ������ġ�� �����ұ��?\n");
			printf("0. �ڷΰ���\n");
			printf("1. MANDO\n");
			printf("2. CONTINENTAL\n");
			printf("3. BOSCH\n");
		}
		else if (step == SteeringSystem_Q) {
			printf(CLEAR_SCREEN);
			printf("� ������ġ�� �����ұ��?\n");
			printf("0. �ڷΰ���\n");
			printf("1. BOSCH\n");
			printf("2. MOBIS\n");
		}
		else if (step == Run_Test) {
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

		if (step == CarType_Q && !(answer >= 1 && answer <= 3)) {
			printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ���� ");
			next();
			continue;
		}

		if (step == Engine_Q && !(answer >= 0 && answer <= 4)) {
			printf("ERROR :: ������ 1 ~ 4 ������ ���� ����");
			next();
			continue;
		}

		if (step == BreakSystem_Q && !(answer >= 0 && answer <= 3)) {
			printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����");
			next();
			continue;
		}

		if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2)) {
			printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����");
			next();
			continue;
		}

		if (step == Run_Test && !(answer >= 0 && answer <= 3)) {
			printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�");
			next();
			continue;
		}

		//ó������ ���ư���
		if (answer == 0 && step == Run_Test) {
			step = CarType_Q;
			continue;
		}

		//�������� ���ư���
		if (answer == 0 && step >= 1) {
			step -= 1;
			continue;
		}

		if (step == CarType_Q) {
			selectCarType(answer);
			delay(1500);
			step = Engine_Q;
		}
		else if (step == Engine_Q) {
			selectEngine(answer);
			delay(1500);
			step = BreakSystem_Q;
		}
		else if (step == BreakSystem_Q) {
			selectBreakSystem(answer);
			delay(1500);
			step = SteeringSystem_Q;
		}
		else if (step == SteeringSystem_Q) {
			selectSteeringSystem(answer);
			delay(1500);
			step = Run_Test;
		}
		else if (step == Run_Test && answer == 1) {
			runProducedCar();
			next();
		}
		else if (step == Run_Test && answer == 2) {
			infoProducedCar();
			next();
		}
		else if (step == Run_Test && answer == 3) {
			testProducedCar();
			next();
		}
	}

}

void selectCarType(int answer) {
	stack[CarType_Q] = answer;
	if (answer == 1) printf("���� Ÿ������ ������ �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("���� Ÿ������ TRUCK�� �����ϼ̽��ϴ�.\n");
}

void selectEngine(int answer) {
	stack[Engine_Q] = answer;
	if (answer == 1) printf("GM ������ �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("WIA ������ �����ϼ̽��ϴ�.\n");
}

void selectBreakSystem(int answer) {
	stack[BreakSystem_Q] = answer;
	if (answer == 1) printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void selectSteeringSystem(int answer) {
	stack[SteeringSystem_Q] = answer;
	if (answer == 1) printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
}

void runProducedCar() {
	if (stack[Engine_Q] == 4) {
		printf("������ ���峵���ϴ�.\n");
		printf("�ڵ����� �������� �ʽ��ϴ�. ");
	}
	else {
		printf("�ڵ����� ���۵˴ϴ�. ");
	}
}

void testProducedCar() {
	if (stack[CarType_Q] == SEDAN && stack[BreakSystem_Q] == CONTINENTAL) {
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