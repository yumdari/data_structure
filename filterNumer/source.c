#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int number = 0;
	scanf("%d", &number);
	int div = 10;
	int arr[100];
	int idx = 0;
	while (number)
	{
		arr[idx] = number % 10;
		number = number / 10;
		idx++;
	}

	for (int jdx = 0; jdx < idx; jdx++) {
		if (arr[jdx] % 2 == 0) {
			printf("%d", arr[jdx]);
		}
	}
	printf(" ");
	for (int jdx = 0; jdx < idx; jdx++) {
		if (arr[jdx] % 2 == 1) {
			printf("%d", arr[jdx]);
		}
	}
}