#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

	char bottle[256] = { 0, };
	int bottle_check = 0;
	int fail = 0;

	while (1) {

		int digit_check = 0;
		int check = 0;

		printf("검사할 괄호 입력 : ");
		scanf_s("%s", bottle, (unsigned)sizeof(bottle));

		for (int i = 0; i < strlen(bottle); i++) {
			if (isdigit(bottle[i])) digit_check++;
			else if (bottle[i] == '(' || bottle[i] == ')') check++;
		}

		if (digit_check > 0 || check != strlen(bottle)) {
			printf("소괄호만 입력해주세요.\n\n");
			for (int i = 0; i < strlen(bottle); i++) {
				bottle[i] = 0;
			}
		}
		else break;
	}

	for (int i = 0; i < strlen(bottle); i++) {
		if (bottle_check < 0) {
			fail++;
		}
		else {
			if (bottle[i] == '(') {
				bottle_check++;
			}
			else if (bottle[i] == ')') {
				bottle_check--;
			}
		}
	}

	if (bottle_check == 0 && fail == 0) {
		printf("올바른 괄호 입니다.\n");
	}
	else {
		printf("잘못된 괄호 입니다.\n");
	}

	return 0;
}