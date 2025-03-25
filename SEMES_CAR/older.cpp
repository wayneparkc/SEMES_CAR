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
			printf("?´ë–¤ ì°¨ëŸ‰ ?€?…ì„ ? íƒ? ê¹Œ??\n");
			printf("1. Sedan\n");
			printf("2. SUV\n");
			printf("3. Truck\n");
			printf("4. ì¢…ë£Œ\n");
			
		}
		else if (step == 2) {
			printf(CLEAR_SCREEN);
			printf("?´ë–¤ ?”ì§„???‘ì¬? ê¹Œ??\n");
			printf("0. ?¤ë¡œê°€ê¸?n");
			printf("1. GM\n");
			printf("2. TOYOTA\n");
			printf("3. WIA\n");
			printf("4. ê³ ì¥???”ì§„\n");
		}
		else if (step == 3) {
			printf(CLEAR_SCREEN);
			printf("?´ë–¤ ?œë™?¥ì¹˜ë¥?? íƒ? ê¹Œ??\n");
			printf("0. ?¤ë¡œê°€ê¸?n");
			printf("1. MANDO\n");
			printf("2. CONTINENTAL\n");
			printf("3. BOSCH\n");
		}
		else if (step == 4) {
			printf(CLEAR_SCREEN);
			printf("?´ë–¤ ì¡°í–¥?¥ì¹˜ë¥?? íƒ? ê¹Œ??\n");
			printf("0. ?¤ë¡œê°€ê¸?n");
			printf("1. BOSCH\n");
			printf("2. MOBIS\n");
		}
		else if (step == 5) {
			printf(CLEAR_SCREEN);
			printf("ë©‹ì§„ ì°¨ëŸ‰???„ì„±?˜ì—ˆ?µë‹ˆ??\n");
			printf("?´ë–¤ ?™ì‘??? ê¹Œ??\n");
			printf("0. ì²˜ìŒ ?”ë©´?¼ë¡œ ?Œì•„ê°€ê¸?n");
			printf("1. RUN\n");
			printf("2. Info\n");
			printf("3. Test\n");
		}
		printf("===============================\n");

		printf("INPUT > ");
		fgets(buf, sizeof(buf), stdin);

		//?”í„° ê°œí–‰ë¬¸ì ?œê±°
		char* c = NULL;
		char* ch = strtok_s(buf, "\r", &c);
		ch = strtok_s(buf, "\n", &c);


		if (!strcmp(buf, "4")) {
			printf("ë°”ì´ë°”ì´\n");
			break;
		}

		//?«ìë¡????€?µì¸ì§€ ?•ì¸
		char* checkNumber;
		int answer = strtol(buf, &checkNumber, 10); //ë¬¸ì?´ì„ 10ì§„ìˆ˜ë¡?ë³€??

		//?…ë ¥ë°›ì? ë¬¸ìê°€ ?«ìê°€ ?„ë‹ˆ?¼ë©´
		if (*checkNumber != '\0') {
			printf("ERROR :: ?«ìë§??…ë ¥ ê°€??);
			next();
			continue;
		}

		if (step == 1 && !(answer >= 1 && answer <= 3)) {
<<<<<<< HEAD
			printf("ERROR :: ì°¨ëŸ‰ ?€?…ì? 1 ~ 3 ë²”ìœ„ë§?? íƒ ê°€??");
=======
			printf("ERROR :: Â÷·® Å¸ÀÔÀº 1 ~ 3 ¹üÀ§¸¸ ¼±ÅÃ °¡´É ");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

		if (step == 2 && !(answer >= 0 && answer <= 4)) {
<<<<<<< HEAD
			printf("ERROR :: ?”ì§„?€ 1 ~ 4 ë²”ìœ„ë§?? íƒ ê°€??);
=======
			printf("ERROR :: ¿£ÁøÀº 1 ~ 4 ¹üÀ§¸¸ ¼±ÅÃ °¡´É");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

		if (step == 3 && !(answer >= 0 && answer <= 3)) {
<<<<<<< HEAD
			printf("ERROR :: ?œë™?¥ì¹˜??1 ~ 3 ë²”ìœ„ë§?? íƒ ê°€??);
=======
			printf("ERROR :: Á¦µ¿ÀåÄ¡´Â 1 ~ 3 ¹üÀ§¸¸ ¼±ÅÃ °¡´É");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

		if (step == 4 && !(answer >= 0 && answer <= 2)) {
<<<<<<< HEAD
			printf("ERROR :: ì¡°í–¥?¥ì¹˜??1 ~ 2 ë²”ìœ„ë§?? íƒ ê°€??);
=======
			printf("ERROR :: Á¶ÇâÀåÄ¡´Â 1 ~ 2 ¹üÀ§¸¸ ¼±ÅÃ °¡´É");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

		if (step == 5 && !(answer >= 0 && answer <= 3)) {
<<<<<<< HEAD
			printf("ERROR :: Run ?ëŠ” Test ì¤??˜ë‚˜ë¥?? íƒ ?„ìš”");
=======
			printf("ERROR :: Run ¶Ç´Â Test Áß ÇÏ³ª¸¦ ¼±ÅÃ ÇÊ¿ä");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
			next();
			continue;
		}

<<<<<<< HEAD
		//ì²˜ìŒ?¼ë¡œ ?Œì•„ê°€ê¸?
=======
		//Ã³À½À¸·Î µ¹¾Æ°¡±â
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
		if (answer == 0 && step == 5) {
			step = 1;
			continue;
		}

		//?´ì „?¼ë¡œ ?Œì•„ê°€ê¸?
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
	if (answer == 1) printf("ì°¨ëŸ‰ ?€?…ìœ¼ë¡??¸ë‹¨??? íƒ?˜ì…¨?µë‹ˆ??\n");
	if (answer == 2) printf("ì°¨ëŸ‰ ?€?…ìœ¼ë¡?SUV??? íƒ?˜ì…¨?µë‹ˆ??\n");
	if (answer == 3) printf("ì°¨ëŸ‰ ?€?…ìœ¼ë¡?TRUCK??? íƒ?˜ì…¨?µë‹ˆ??\n");
=======
	if (answer == 1) printf("Â÷·® Å¸ÀÔÀ¸·Î ¼¼´ÜÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
	if (answer == 2) printf("Â÷·® Å¸ÀÔÀ¸·Î SUVÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
	if (answer == 3) printf("Â÷·® Å¸ÀÔÀ¸·Î TRUCKÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
}

void selectEngine(int answer) {
	stack[2] = answer;
<<<<<<< HEAD
	if (answer == 1) printf("GM ?”ì§„??? íƒ?˜ì…¨?µë‹ˆ??\n");
	if (answer == 2) printf("TOYOTA ?”ì§„??? íƒ?˜ì…¨?µë‹ˆ??\n");
	if (answer == 3) printf("WIA ?”ì§„??? íƒ?˜ì…¨?µë‹ˆ??\n");
=======
	if (answer == 1) printf("GM ¿£ÁøÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
	if (answer == 2) printf("TOYOTA ¿£ÁøÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
	if (answer == 3) printf("WIA ¿£ÁøÀ» ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
}

void selectBreakSystem(int answer) {
	stack[3] = answer;
<<<<<<< HEAD
	if (answer == 1) printf("MANDO ?œë™?¥ì¹˜ë¥?? íƒ?˜ì…¨?µë‹ˆ??\n");
	if (answer == 2) printf("CONTINENTAL ?œë™?¥ì¹˜ë¥?? íƒ?˜ì…¨?µë‹ˆ??\n");
	if (answer == 3) printf("BOSCH ?œë™?¥ì¹˜ë¥?? íƒ?˜ì…¨?µë‹ˆ??\n");
=======
	if (answer == 1) printf("MANDO Á¦µ¿ÀåÄ¡¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
	if (answer == 2) printf("CONTINENTAL Á¦µ¿ÀåÄ¡¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
	if (answer == 3) printf("BOSCH Á¦µ¿ÀåÄ¡¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
}

void selectSteeringSystem(int answer) {
	stack[4] = answer;
<<<<<<< HEAD
	if (answer == 1) printf("BOSCH ?œë™?¥ì¹˜ë¥?? íƒ?˜ì…¨?µë‹ˆ??\n");
	if (answer == 2) printf("MOBIS ?œë™?¥ì¹˜ë¥?? íƒ?˜ì…¨?µë‹ˆ??\n");
=======
	if (answer == 1) printf("BOSCH Á¦µ¿ÀåÄ¡¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
	if (answer == 2) printf("MOBIS Á¦µ¿ÀåÄ¡¸¦ ¼±ÅÃÇÏ¼Ì½À´Ï´Ù.\n");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
}

void runProducedCar() {
	if (stack[2] == 4) {
<<<<<<< HEAD
		printf("?”ì§„??ê³ ì¥?¬ìŠµ?ˆë‹¤.\n");
		printf("?ë™ì°¨ê? ?€ì§ì´ì§€ ?ŠìŠµ?ˆë‹¤. ");
=======
		printf("¿£ÁøÀÌ °íÀå³µ½À´Ï´Ù.\n");
		printf("ÀÚµ¿Â÷°¡ ¿òÁ÷ÀÌÁö ¾Ê½À´Ï´Ù. ");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
	}
	else {
		printf("?ë™ì°¨ê? ?™ì‘?©ë‹ˆ?? ");
	}
}

/*
void testProducedCar() {
	if (stack[1] == static_cast<int>(CarType::SEDAN) && stack[3] == static_cast<int>(CarType::CONTINENTAL)) {
<<<<<<< HEAD
		printf("?ë™ì°??ŒìŠ¤??ê²°ê³¼ : FAIL\n");
		printf("Sedan?€ Continental ?œë™?¥ì¹˜ë¥??????†ìŠµ?ˆë‹¤ ");
=======
		printf("ÀÚµ¿Â÷ Å×½ºÆ® °á°ú : FAIL\n");
		printf("SedanÀº Continental Á¦µ¿ÀåÄ¡¸¦ ¾µ ¼ö ¾ø½À´Ï´Ù ");
>>>>>>> a018d5c299019ceaebc7f3b841d3083587a1a32a
	}
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA) {
		printf("?ë™ì°??ŒìŠ¤??ê²°ê³¼ : FAIL\n");
		printf("SUV???„ìš”?€ ?”ì§„???????†ìŠµ?ˆë‹¤. ");
	}
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA) {
		printf("?ë™ì°??ŒìŠ¤??ê²°ê³¼ : FAIL\n");
		printf("Truck?€ WIA ?”ì§„???????†ìŠµ?ˆë‹¤. ");
	}
	else if (stack[CarType_Q] == TRUCK && stack[BreakSystem_Q] == MANDO) {
		printf("?ë™ì°??ŒìŠ¤??ê²°ê³¼ : FAIL\n");
		printf("Truck?€ MANDO ?œë™?¥ì¹˜ë¥??????†ìŠµ?ˆë‹¤. ");
	}
	else if (stack[BreakSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S) {
		printf("?ë™ì°??ŒìŠ¤??ê²°ê³¼ : FAIL\n");
		printf("?œë™?¥ì¹˜??Bosch ?œí’ˆ???¼ë‹¤ë©? ì¡°í–¥?¥ì¹˜??Bosch ?œí’ˆ???¨ì•¼?©ë‹ˆ?? ");
	}
	else if (stack[BreakSystem_Q] != BOSCH_B && stack[SteeringSystem_Q] == BOSCH_S) {
		printf("?ë™ì°??ŒìŠ¤??ê²°ê³¼ : FAIL\n");
		printf("ì¡°í–¥?¥ì¹˜??Bosch ?œí’ˆ???¼ë‹¤ë©? ?œë™?¥ì¹˜??Bosch ?œí’ˆ???¨ì•¼?©ë‹ˆ?? ");
	}
	else {
		printf("?ë™ì°??ŒìŠ¤??ê²°ê³¼ : PASS ");
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
	printf("?œì¡°???ë™ì°??•ë³´\n");
	printf("ì°¨ëŸ‰ ?€??: ");
	printf("\n");
	printf("??    ì§?: ");
	printf("\n");
	printf("?œë™ ?¥ì¹˜ : ");
	printf("\n");
	printf("ì¡°í–¥ ?¥ì¹˜ : ");
	printf("\n");
	printf("===============================\n");
	printf("?•ë³´ ?«ê¸° ");
}
*/