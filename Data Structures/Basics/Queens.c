#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void nqueens(int r, int n, int column[]);
int place(int r, int c, int column[]);

void main() {
    int n;
    int column[50];
    clrscr();
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nqueens(1, n, column); //placing queen 1 in row 1
    getch();
}

void nqueens(int r, int n, int column[]) {
    int i, c;
    for (c = 1; c <= n; c++) {
        if (place(r, c, column)) {
            //place queen r in row r and column c
            column[r] = c;
            if (r == n) { //all queens are placed
                for (i = 1; i <= n; i++) {
                    printf("Queen no %d is placed in row %d and column %d \n", i, i, column[i]);
                }
                getch();
                exit(1);
            } else {
                nqueens(r + 1, n, column); //place the next queen
            }
        }
    }
}

int place(int r, int c, int column[]) {
    int j;
    for (j = 1; j <= r - 1; j++) {
        if ((column[j] == c) || ((abs(column[j] - c)) == (abs(j - r)))) {
            return 0;
        }
    }
    return 0;
}
