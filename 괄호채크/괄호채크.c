#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

	// ���� ���� �� �ʱ�ȭ
	char bottle[256] = { 0, };
	int count = 0;
	int fail = 0;

	while (1) {

		// ���� ���� �� �ʱ�ȭ
		int digit_check = 0;
		int check = 0;

		printf("�˻��� ��ȣ �Է� : ");
		scanf_s("%s", bottle, (unsigned)sizeof(bottle));

		// �Է� ���� ���ڿ��� ���ڳ� �Ұ�ȣ�� ������ ���� ����
		for (int i = 0; i < strlen(bottle); i++) {
			if (isdigit(bottle[i])) digit_check++;
			else if (bottle[i] == '(' || bottle[i] == ')') check++;
		}

		// ���ڰ� �ְų� �Ұ�ȣ�� ���� ��ü �迭�� ���� ���� ������ ���Է� �� �迭 �ʱ�ȭ
		if (digit_check > 0 || check != strlen(bottle)) {
			printf("�Ұ�ȣ�� �Է����ּ���.\n\n");
			for (int i = 0; i < strlen(bottle); i++) {
				bottle[i] = 0;
			}
		}
		else break; // ���ڰ� ���� �Ұ�ȣ�� ���� ��ü �迭�� ���� ������ break
	}

	// �迭�� ���� ��ŭ �ݺ�
	for (int i = 0; i < strlen(bottle); i++) {
		// count�� 0 ���� ������ fail ����
		if (count < 0) {
			fail++;
		}
		// count�� 0 ���� Ŭ ��
		else {
			// bottle[i] �� '(' �� count ����
			if (bottle[i] == '(') {
				count++;
			}
			// bottle[i] �� ')' �� count �϶�
			else if (bottle[i] == ')') {
				count--;
			}
		}
	}

	//count�� 0�̰� fail�� 0�̸� ���� �ƴϸ� ����
	if (count == 0 && fail == 0) {
		printf("�ùٸ� ��ȣ �Դϴ�.\n");
	}
	else {
		printf("�߸��� ��ȣ �Դϴ�.\n");
	}

	return 0;
}