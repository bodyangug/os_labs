#include <stdlib.h>
#include <stdio.h>
#include "lib/matrix.h"

int main(int argc, char const *argv[]){
    printf("InitMatrixByConsole operation\n");
    Matrix* matrix1 = newMatrix(2,2);
    initMatrixByConsole(matrix1);
    printMatrix(matrix1);

    printf("SaveMatrixInFile operation\n");
    saveMatrixInFile(matrix1,"matrix.data");

    printf("Read saved matrix\n");
    Matrix* savedMatrix = readMatrixFromTheFile("matrix.data");

    printf("Print saved matrix:\n");
    printMatrix(savedMatrix);

    printf("Creat second matrix by console\n");
    Matrix* matrix2 = newMatrix(2,2);
    initMatrixByConsole(matrix2);

    printf("Print matrix1\n");
    printMatrix(matrix1);
    printf("Print matrix2\n");
    printMatrix(matrix2);

    printf("Sum of matrix1 and matrix2: \n");
    Matrix* sumMatrix = sum(matrix1,matrix2);
    printMatrix(sumMatrix);

    printf("Subtraction of matrix1 and matrix2: \n");
    Matrix* subtractionMatrix = subtraction(matrix1,matrix2);
    printMatrix(subtractionMatrix);

    printf("Set operation into matrix1\n");
    set(matrix1,0,0,999);
    printf("Get: %0.2lf\n", get(matrix1,0,0));

    printf("Resize matrix1\n");
    resizeMatrix(matrix1,3,2);
    printf("Resize matrix2\n");
    resizeMatrix(matrix2,2,3);

    printf("\n");
    printf("InitMatrixByConsole operation\n");
    initMatrixByConsole(matrix1);
    printf("InitMatrixByConsole operation\n");
    initMatrixByConsole(matrix2);

    printf("Print matrix1\n");
    printMatrix(matrix1);
    printf("Print matrix2\n");
    printMatrix(matrix2);

    printf("Multiplication matrix:\n");
    Matrix* multiplicationMatrix = multiplication(matrix1,matrix2);
    printMatrix(multiplicationMatrix);

    printf("Multiplication to num: 2\n");
    Matrix* multiplicationMatrixByNumber = multiplicatioByNumber(matrix1,2);
    printMatrix(multiplicationMatrixByNumber);

    printf("Clear operation\n");
    clearMatrix(matrix1);
    clearMatrix(matrix2);
    clearMatrix(sumMatrix);
    clearMatrix(subtractionMatrix);
    clearMatrix(multiplicationMatrix);
    clearMatrix(multiplicationMatrixByNumber);
    printf("END\n");
    return 0;
}
