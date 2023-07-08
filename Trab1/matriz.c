#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void multiply_matrices(int A[][SIZE], int B[][SIZE], int C[][SIZE]) {
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print_matrix(int matrix[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    int C[SIZE][SIZE];
    int i, j;

    // Inicializa a semente aleatória
    srand(time(0));

    // Preenche as matrizes A e B com valores aleatórios
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = rand() % 10;  // valores aleatórios de 0 a 9
            B[i][j] = rand() % 10;  // valores aleatórios de 0 a 9
        }
    }

    // Realiza a multiplicação das matrizes A e B
    multiply_matrices(A, B, C);

    // Imprime a matriz resultante C
    print_matrix(C);

    return 0;
}
