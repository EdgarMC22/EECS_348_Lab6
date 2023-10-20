#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;

void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, std::string fileName);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size, std::string name);
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int matrixSum[MAX_SIZE][MAX_SIZE];
    int matrixProduct[MAX_SIZE][MAX_SIZE];
    int matrixDifference[MAX_SIZE][MAX_SIZE];
    int size;

    readMatrixFromFile(matrixA, matrixB, size, "matrix_input.txt");
    printMatrix(matrixA, size, "Matrix A");
    printMatrix(matrixB, size, "Matrix B");

    addMatrices(matrixA, matrixB, matrixSum, size);
    multiplyMatrices(matrixA, matrixB, matrixProduct, size);
    subtractMatrices(matrixA, matrixB, matrixDifference, size);

    printMatrix(matrixSum, size, "Matrix Sum (A + B)");
    printMatrix(matrixProduct, size, "Matrix Product (A * B)");
    printMatrix(matrixDifference, size, "Matrix Difference (A - B)");

    return 0;
}

// Function Definitions
void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, std::string fileName) {
    std::ifstream file(fileName);
    if (!file){
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(1);
    }
    file >> size;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            file >> matrixA[i][j];
        }
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            file >> matrixB[i][j];
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE],int size, std::string name) {
    std::cout << "\n" << name << ":\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
