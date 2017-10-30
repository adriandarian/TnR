#include<stdio.h>
#include<stdlib.h>
#define size 7

int is_sorted(int *, int);
void shuffle(int *, int);
void bogosort(int *, nt);

int main() {
    int numbers[size];
    int i;
    printf("Enter the elements of array:");
    for (i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    bogosort(numbers, size);
    printf("The array after sorting is:");
    for (i = 0; i < size; i++) {
        printf("%d\n", numbers[i]);
    }
    printf("\n");
}

/*Check if the array is sorted or not*/
int is_sorted(int *a, int n) {
    while (--n >= 1) {
        if (a[n] < a[n - 1]) {
            return 0;
        }
    }
    return 1;
}

/*To shuffle the array elements*/
void shuffle(int *a, int n) {
    int i, t, temp;
    for (i = 0; i < n; i++) {
        t = a[i];
        temp = rand() % n;
        a[i] = a[temp];
        a[temp] = t;
    }
}

/*Check to see if the array is sorted or not, and if not then sorts the array*/
void bogosort(int *a, int n) {
    while (!is_sorted(a, n)) {
        shuffle(a, n);
    }
}
