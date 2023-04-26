#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

	// 변수 선언 및 초기화
	char bottle[256] = { 0, };
	int count = 0;
	int fail = 0;

	while (1) {

		// 변수 선언 및 초기화
		int digit_check = 0;
		int check = 0;

		printf("검사할 괄호 입력 : ");
		scanf_s("%s", bottle, (unsigned)sizeof(bottle));

		// 입력 받은 문자열에 숫자나 소괄호가 있으면 변수 증가
		for (int i = 0; i < strlen(bottle); i++) {
			if (isdigit(bottle[i])) digit_check++;
			else if (bottle[i] == '(' || bottle[i] == ')') check++;
		}

		// 숫자가 있거나 소괄호의 수가 전체 배열의 수와 맞지 않으면 재입력 및 배열 초기화
		if (digit_check > 0 || check != strlen(bottle)) {
			printf("소괄호만 입력해주세요.\n\n");
			for (int i = 0; i < strlen(bottle); i++) {
				bottle[i] = 0;
			}
		}
		else break; // 숫자가 없고 소괄호의 수가 전체 배열의 수와 맞으면 break
	}

	// 배열의 길이 만큼 반복
	for (int i = 0; i < strlen(bottle); i++) {
		// count가 0 보다 작으면 fail 증가
		if (count < 0) {
			fail++;
		}
		// count가 0 보다 클 때
		else {
			// bottle[i] 가 '(' 면 count 증가
			if (bottle[i] == '(') {
				count++;
			}
			// bottle[i] 가 ')' 면 count 하락
			else if (bottle[i] == ')') {
				count--;
			}
		}
	}

	//count가 0이고 fail이 0이면 정답 아니면 실패
	if (count == 0 && fail == 0) {
		printf("올바른 괄호 입니다.\n");
	}
	else {
		printf("잘못된 괄호 입니다.\n");
	}

	return 0;
}