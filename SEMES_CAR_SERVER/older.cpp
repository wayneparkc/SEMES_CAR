/*


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
void testProducedCar();
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
			printf("?�떤 차량 ?�?�을 ?�택?�까??\n");
			printf("1. Sedan\n");
			printf("2. SUV\n");
			printf("3. Truck\n");
			printf("4. 종료\n");
			
		}
		else if (step == 2) {
			printf(CLEAR_SCREEN);
			printf("?�떤 ?�진???�재?�까??\n");
			printf("0. ?�로가�?n");
			printf("1. GM\n");
			printf("2. TOYOTA\n");
			printf("3. WIA\n");
			printf("4. 고장???�진\n");
		}
		else if (step == 3) {
			printf(CLEAR_SCREEN);
			printf("?�떤 ?�동?�치�??�택?�까??\n");
			printf("0. ?�로가�?n");
			printf("1. MANDO\n");
			printf("2. CONTINENTAL\n");
			printf("3. BOSCH\n");
		}
		else if (step == 4) {
			printf(CLEAR_SCREEN);
			printf("?�떤 조향?�치�??�택?�까??\n");
			printf("0. ?�로가�?n");
			printf("1. BOSCH\n");
			printf("2. MOBIS\n");
		}
		else if (step == 5) {
			printf(CLEAR_SCREEN);
			printf("멋진 차량???�성?�었?�니??\n");
			printf("?�떤 ?�작???�까??\n");
			printf("0. 처음 ?�면?�로 ?�아가�?n");
			printf("1. RUN\n");
			printf("2. Info\n");
			printf("3. Test\n");
		}
		printf("===============================\n");

		printf("INPUT > ");
		fgets(buf, sizeof(buf), stdin);

		//?�터 개행문자 ?�거
		char* c = NULL;
		char* ch = strtok_s(buf, "\r", &c);
		ch = strtok_s(buf, "\n", &c);


		if (!strcmp(buf, "4")) {
			printf("바이바이\n");
			break;
		}

		//?�자�????�?�인지 ?�인
		char* checkNumber;
		int answer = strtol(buf, &checkNumber, 10); //문자?�을 10진수�?변??

		//?�력받�? 문자가 ?�자가 ?�니?�면
		if (*checkNumber != '\0') {
			printf("ERROR :: ?�자�??�력 가??);
			next();
			continue;
		}

		if (step == 1 && !(answer >= 1 && answer <= 3)) {
<<<<<<< HEAD
			printf("ERROR :: 차량 ?�?��? 1 ~ 3 범위�??�택 가??");
=======
			printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ���� ");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

		if (step == 2 && !(answer >= 0 && answer <= 4)) {
<<<<<<< HEAD
			printf("ERROR :: ?�진?� 1 ~ 4 범위�??�택 가??);
=======
			printf("ERROR :: ������ 1 ~ 4 ������ ���� ����");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

		if (step == 3 && !(answer >= 0 && answer <= 3)) {
<<<<<<< HEAD
			printf("ERROR :: ?�동?�치??1 ~ 3 범위�??�택 가??);
=======
			printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

		if (step == 4 && !(answer >= 0 && answer <= 2)) {
<<<<<<< HEAD
			printf("ERROR :: 조향?�치??1 ~ 2 범위�??�택 가??);
=======
			printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

		if (step == 5 && !(answer >= 0 && answer <= 3)) {
<<<<<<< HEAD
			printf("ERROR :: Run ?�는 Test �??�나�??�택 ?�요");
=======
			printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

<<<<<<< HEAD
		//처음?�로 ?�아가�?
=======
		//ó������ ���ư���
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
		if (answer == 0 && step == 5) {
			step = 1;
			continue;
		}

		//?�전?�로 ?�아가�?
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
		else if (step == 5 && answer == 3) {
			testProducedCar();
			next();
		}
	}

}

void selectCarType(int answer) {
	stack[1] = answer;
<<<<<<< HEAD
	if (answer == 1) printf("차량 ?�?�으�??�단???�택?�셨?�니??\n");
	if (answer == 2) printf("차량 ?�?�으�?SUV???�택?�셨?�니??\n");
	if (answer == 3) printf("차량 ?�?�으�?TRUCK???�택?�셨?�니??\n");
=======
	if (answer == 1) printf("���� Ÿ������ ������ �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("���� Ÿ������ TRUCK�� �����ϼ̽��ϴ�.\n");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
}

void selectEngine(int answer) {
	stack[2] = answer;
<<<<<<< HEAD
	if (answer == 1) printf("GM ?�진???�택?�셨?�니??\n");
	if (answer == 2) printf("TOYOTA ?�진???�택?�셨?�니??\n");
	if (answer == 3) printf("WIA ?�진???�택?�셨?�니??\n");
=======
	if (answer == 1) printf("GM ������ �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("WIA ������ �����ϼ̽��ϴ�.\n");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
}

void selectBreakSystem(int answer) {
	stack[3] = answer;
<<<<<<< HEAD
	if (answer == 1) printf("MANDO ?�동?�치�??�택?�셨?�니??\n");
	if (answer == 2) printf("CONTINENTAL ?�동?�치�??�택?�셨?�니??\n");
	if (answer == 3) printf("BOSCH ?�동?�치�??�택?�셨?�니??\n");
=======
	if (answer == 1) printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 3) printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
}

void selectSteeringSystem(int answer) {
	stack[4] = answer;
<<<<<<< HEAD
	if (answer == 1) printf("BOSCH ?�동?�치�??�택?�셨?�니??\n");
	if (answer == 2) printf("MOBIS ?�동?�치�??�택?�셨?�니??\n");
=======
	if (answer == 1) printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 2) printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
}

void runProducedCar() {
	if (stack[2] == 4) {
<<<<<<< HEAD
		printf("?�진??고장?�습?�다.\n");
		printf("?�동차�? ?�직이지 ?�습?�다. ");
=======
		printf("������ ���峵���ϴ�.\n");
		printf("�ڵ����� �������� �ʽ��ϴ�. ");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
	}
	else {
		printf("?�동차�? ?�작?�니?? ");
	}
}

/*
void testProducedCar() {
	if (stack[1] == static_cast<int>(CarType::SEDAN) && stack[3] == static_cast<int>(CarType::CONTINENTAL)) {
<<<<<<< HEAD
		printf("?�동�??�스??결과 : FAIL\n");
		printf("Sedan?� Continental ?�동?�치�??????�습?�다 ");
=======
		printf("�ڵ��� �׽�Ʈ ��� : FAIL\n");
		printf("Sedan�� Continental ������ġ�� �� �� �����ϴ� ");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
	}
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA) {
		printf("?�동�??�스??결과 : FAIL\n");
		printf("SUV???�요?� ?�진???????�습?�다. ");
	}
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA) {
		printf("?�동�??�스??결과 : FAIL\n");
		printf("Truck?� WIA ?�진???????�습?�다. ");
	}
	else if (stack[CarType_Q] == TRUCK && stack[BreakSystem_Q] == MANDO) {
		printf("?�동�??�스??결과 : FAIL\n");
		printf("Truck?� MANDO ?�동?�치�??????�습?�다. ");
	}
	else if (stack[BreakSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S) {
		printf("?�동�??�스??결과 : FAIL\n");
		printf("?�동?�치??Bosch ?�품???�다�? 조향?�치??Bosch ?�품???�야?�니?? ");
	}
	else if (stack[BreakSystem_Q] != BOSCH_B && stack[SteeringSystem_Q] == BOSCH_S) {
		printf("?�동�??�스??결과 : FAIL\n");
		printf("조향?�치??Bosch ?�품???�다�? ?�동?�치??Bosch ?�품???�야?�니?? ");
	}
	else {
		printf("?�동�??�스??결과 : PASS ");
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
	printf("?�조???�동�??�보\n");
	printf("차량 ?�??: ");
	printf("\n");
	printf("??    �?: ");
	printf("\n");
	printf("?�동 ?�치 : ");
	printf("\n");
	printf("조향 ?�치 : ");
	printf("\n");
	printf("===============================\n");
	printf("?�보 ?�기 ");
}
*/