#include <stdio.h>
char* LuckyNumber();
void main() 
{
	int n;
	int k;
	printf("Enter your number (max 10 digits): ");
	scanf_s("%i", &n);

	printf("Enter your key (1-9): ");
	scanf_s("%i", &k);
;
	printf("%s", LuckyNumber(n,k));
}

char* LuckyNumber(int n, int k) {
	int arrnum = 0;
	int reversed[10];

	//	Entering number N into array
	while (n != 0)
	{
		reversed[arrnum] = n % 10;
		n = n / 10;
		arrnum++;
	}

	int startnum[10];

	//	Reversing array
	for (int i = 0; i < arrnum; i++)
	{
		startnum[i] = reversed[arrnum - 1 - i];
	}

	int i = -1;
	int newnum = arrnum;
	int j = 0;
	int endnum[10];
	int sum = 0;

	//	Creating and entering value of new number depending on key into new array
	do {
		int skippednumberscounter = k;
		do
		{
			i++;
			if (i >= arrnum) {
				i -= arrnum;
			}
			if (startnum[i] != 10) {
				skippednumberscounter--;
			}
		} while (skippednumberscounter != 0);
		if (startnum[i] != 10) {
			endnum[j] = startnum[i];
			startnum[i] = 10;
			newnum--;
			sum += endnum[j];

			j++;
		}
		else
			i++;
	} while (newnum != 0);
	for (i = 0; i < arrnum; i++) {
		printf("%i", endnum[i]);
	}
	if (sum % 3 == 0)
		return "\nYes";
	else
		return "\nNo";
}