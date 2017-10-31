#include<stdio.h>
#define MAX 10

in min_linearsearch(int numbers[]) {
	int min = numbers[0];
	int i;
	for (i = 1; i < MAX; i++)
		if (min > numbers[i])
			min = numbers[i];
	return min;
}

int main() {
	int numbers[MAX];
	int i;
	int min;
	printf("Enter %d numbers : ", MAX);
	for (i = 0; i < MAX; i++)
		scanf("%d", &numbers[i]);
	min = min_linearsearch(numbers);
	printf("\nMinimum number in the array is : %d\n", min);
	return 0;
}
