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

		printf("�˻��� ��ȣ �Է� : ");
		scanf_s("%s", bottle, (unsigned)sizeof(bottle));

		for (int i = 0; i < strlen(bottle); i++) {
			if (isdigit(bottle[i])) digit_check++;
			else if (bottle[i] == '(' || bottle[i] == ')') check++;
		}

		if (digit_check > 0 || check != strlen(bottle)) {
			printf("�Ұ�ȣ�� �Է����ּ���.\n\n");
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
		printf("�ùٸ� ��ȣ �Դϴ�.\n");
	}
	else {
		printf("�߸��� ��ȣ �Դϴ�.\n");
	}

	return 0;
}