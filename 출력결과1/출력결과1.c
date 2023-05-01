#include <stdio.h>

int main() {
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y <= 2; y++) {
			printf("x = %d, y = %d\n", x, y);
		}
		printf("*---*---*\n");
	}
	return 0;
}