#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	srand((unsigned)time(NULL));
	int runtime;
	char bottle[256] = { 0, };
	int count = 0;
	int random_2;

	printf("채크할 횟수 : ");
	scanf_s("%d", &runtime);

	for (int i = 0; i < runtime; i++) {
		while (1) {
			random_2 = rand() % 10 + 2;
			if (random_2 % 2 == 0) break;
		}
		for (int j = 0; j < random_2; j++) {
			int random = rand() % 2;
			bottle[j] = (random == 0) ? '(' : ')';
		}

		
		printf("\n[%d번째 채크]\n", i + 1);

		for (int j = 0; j < strlen(bottle); j++) {
			if (count < 0) break;
			else {
				bottle[j] == '(' ? count++ : count--;
			}
		}

		if (count == 0) {
			printf("%s\n올바른 괄호 입니다.\n", bottle);
		}
		else {
			printf("%s\n잘못된 괄호 입니다.\n", bottle);
		}

		for (int j = 0; bottle[j] != '\0'; j++) bottle[j] = 0;

		count = 0;

	}

	return 0;
}