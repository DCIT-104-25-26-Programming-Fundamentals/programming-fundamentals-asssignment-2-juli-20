// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Function to read a matrix from user
void readMatrix(int matrix[][MAX_SIZE], int rows, int cols, string name) {
    cout << "Enter elements for Matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

// =============================================================================
// PART A — Transpose a Matrix
// =============================================================================
void transposeMatrix() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    
    cout << "\n=== PART A: Transpose Matrix ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    readMatrix(matrix, rows, cols, "A");
    
    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);
    
    cout << "\nTransposed Matrix:" << endl;
    // Display transposed (swap rows and cols)
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << setw(6) << matrix[j][i];
        }
        cout << endl;
    }
}

// =============================================================================
// PART B — Add Two Matrices
// =============================================================================
void addMatrices() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    
    cout << "\n=== PART B: Add Two Matrices ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    readMatrix(matrixA, rows, cols, "A");
    readMatrix(matrixB, rows, cols, "B");
    
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rows, cols);
    
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, rows, cols);
    
    // Add matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    cout << "\nSum (A + B):" << endl;
    displayMatrix(result, rows, cols);
}

// =============================================================================
// PART C — Multiply Two Matrices
// =============================================================================
void multiplyMatrices() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    
    cout << "\n=== PART C: Multiply Two Matrices ===" << endl;
    
    // Read matrix A
    cout << "Matrix A:" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;
    readMatrix(matrixA, rowsA, colsA, "A");
    
    // Read matrix B
    cout << "\nMatrix B:" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsB;
    cout << "Enter number of columns: ";
    cin >> colsB;
    
    // Check if multiplication is possible
    if (colsA != rowsB) {
        cout << "\nError: Number of columns in A (" << colsA 
             << ") must equal number of rows in B (" << rowsB << ")" << endl;
        return;
    }
    
    readMatrix(matrixB, rowsB, colsB, "B");
    
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rowsA, colsA);
    
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, rowsB, colsB);
    
    // Multiply matrices: result = A * B
    // Initialize result with zeros
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }
    
    // Perform multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    cout << "\nProduct (A × B):" << endl;
    displayMatrix(result, rowsA, colsB);
}

// =============================================================================
// Main Menu
// =============================================================================
int main() {
    int choice;
    
    cout << "=== MATRIX OPERATIONS ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            transposeMatrix();
            break;
        case 2:
            addMatrices();
            break;
        case 3:
            multiplyMatrices();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
} 