#include <stdio.h>

void LuckyNumber();
void main() {
	LuckyNumber();
}
void LuckyNumber() {
	long n = 0;
	int k = 0;
	printf("Enter your number (max 10 digits): ");
	scanf_s("%i", &n);
	printf("Enter your key (1-9): ");
	scanf_s("%i", &k);
	int num = 0;
	int* ptrReversed = (int*)malloc(10 * sizeof(int));
	
	while (n != 0)
	{
		ptrReversed[num] = n % 10;
		n = n / 10;
		num++;
	}
	int z = 0;
	int* ptrA = (int*)malloc(10 * sizeof(int));
	
	for (z = 0; z < num; z++)
	{
		ptrA[z] = ptrReversed[num - 1 - z];
	}
	int i = -1;
	int newnum = num;
	int j = 0;
	int* ptrM = (int*)malloc(10 * sizeof(int));
	int sum = 0;
	do {
		int f = k;
		do
		{
			i++;
			if (i >= num) {
				i -= num;
			}
			if (ptrA[i] != 10) {
				f--;
			}
		} while (f != 0);
		if (ptrA[i] != 10) {
			ptrM[j] = ptrA[i];
			ptrA[i] = 10;
			newnum--;
			sum += ptrM[j];
			j++;
		}
		else
			i++;
	} while (newnum != 0);
	for (i = 0; i < num; i++) {
		printf("%i", ptrM[i]);
	}
	if (sum % 3 == 0)
		printf("\nYES");
	else
		printf("\nNO");
}