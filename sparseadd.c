#include <stdio.h>

#define SIZE 5   
#define MAX 30   


void convertToCompact(int matrix[SIZE][SIZE], int compact[MAX][3], int *count) {
    int k = 1; 
    *count = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] != 0) {
                compact[k][0] = i;         
                compact[k][1] = j;         
                compact[k][2] = matrix[i][j]; 
                k++;
                (*count)++;
            }
        }
    }

   
    compact[0][0] = SIZE;
    compact[0][1] = SIZE;
    compact[0][2] = *count;
}


void displayCompact(int compact[MAX][3], int count) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", compact[i][0], compact[i][1], compact[i][2]);
    }
    printf("\n");
}


int addCompact(int A[MAX][3], int B[MAX][3], int result[MAX][3]) {
    int i = 1, j = 1, k = 1;
    result[0][0] = A[0][0]; 
    result[0][1] = A[0][1]; 

    while (i <= A[0][2] && j <= B[0][2]) {
        
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++;
        } else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++;
        } else {
           
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
        }
        k++;
    }

    
    while (i <= A[0][2]) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++; k++;
    }
    while (j <= B[0][2]) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++; k++;
    }

    result[0][2] = k - 1; 
    return result[0][2];
}


void transposeCompact(int original[MAX][3], int transposed[MAX][3]) {
    transposed[0][0] = original[0][1]; 
    transposed[0][1] = original[0][0]; 
    transposed[0][2] = original[0][2]; 

    int k = 1;
    for (int col = 0; col < original[0][1]; col++) {
        for (int i = 1; i <= original[0][2]; i++) {
            if (original[i][1] == col) {
                transposed[k][0] = original[i][1];
                transposed[k][1] = original[i][0];
                transposed[k][2] = original[i][2];
                k++;
            }
        }
    }
}


int main() {
    int matrixA[SIZE][SIZE] = {
        {0, 0, 0, 0, 5},
        {0, 0, 8, 0, 0},
        {0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0},
        {3, 0, 0, 6, 0}
    };

    int matrixB[SIZE][SIZE] = {
        {0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {4, 0, 0, 0, 0},
        {0, 0, 0, 9, 0},
        {1, 0, 0, 0, 0}
    };

    int compactA[MAX][3], compactB[MAX][3], result[MAX][3], transpose[MAX][3];
    int countA, countB, resultCount;

    
    convertToCompact(matrixA, compactA, &countA);
    convertToCompact(matrixB, compactB, &countB);

   
    printf("Compact form of Matrix A:\n");
    displayCompact(compactA, countA);

    printf("Compact form of Matrix B:\n");
    displayCompact(compactB, countB);

    
    resultCount = addCompact(compactA, compactB, result);
    printf("Sum of A and B in compact form:\n");
    displayCompact(result, resultCount);

   
    transposeCompact(result, transpose);
    printf("Transpose of the result:\n");
    displayCompact(transpose, resultCount);

    return 0;
}

