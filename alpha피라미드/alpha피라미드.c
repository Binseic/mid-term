#include <stdio.h>

int main() {

	while (1) {

		int input = 0;
		printf("�� �� (0 �Է½� ����) : ");
		int input_check = scanf_s("%d", &input);

		if (!input_check) {
			printf("���ڸ� �Է����ּ���.\n\n");
			char flesh[256];
			scanf_s("%s", flesh, (unsigned)sizeof(flesh));
			continue;
		}
		else if (input < 0) {
			printf("����� �Է����ּ���.\n\n");
			continue;
		}

		if (input == 0) {
			printf("�����մϴ�.\n");
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