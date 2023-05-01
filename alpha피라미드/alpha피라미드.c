#include <stdio.h>

int main() {

	while (1) {

		int input = 0;
		printf("몇 층 (0 입력시 종료) : ");
		int input_check = scanf_s("%d", &input);

		if (!input_check) {
			printf("숫자만 입력해주세요.\n\n");
			char flesh[256];
			scanf_s("%s", flesh, (unsigned)sizeof(flesh));
			continue;
		}
		else if (input < 0) {
			printf("양수만 입력해주세요.\n\n");
			continue;
		}

		if (input == 0) {
			printf("종료합니다.\n");
			break;
		}
		else {
			for (int i = 0; i < input; i++) {
				for (int j = i + 1; j < input; j++) {
					printf(" ");
				}
				for (int k = 0; k < i + 1; k++) {
					printf("%c", 65 + (k % 26));
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}