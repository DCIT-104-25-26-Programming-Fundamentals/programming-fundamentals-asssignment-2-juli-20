// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// =============================================================================
// PART A — Print the First N Terms
// =============================================================================
void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    
    cout << "Fibonacci sequence: ";
    
    // Handle first two terms separately
    if (n >= 1) {
        cout << "0 ";
    }
    if (n >= 2) {
        cout << "1 ";
    }
    
    // Generate and print remaining terms
    int first = 0;
    int second = 1;
    int next;
    
    for (int i = 3; i <= n; i++) {
        next = first + second;
        cout << next << " ";
        first = second;
        second = next;
    }
    cout << endl;
}

// =============================================================================
// PART B — Check if a Number Belongs to the Sequence
// =============================================================================
bool isFibonacci(int num) {
    if (num < 0) {
        return false;  // Negative numbers are not Fibonacci
    }
    
    if (num == 0 || num == 1) {
        return true;  // 0 and 1 are Fibonacci numbers
    }
    
    int first = 0;
    int second = 1;
    int next = 0;
    
    // Generate Fibonacci numbers until we reach or exceed the input
    while (next < num) {
        next = first + second;
        if (next == num) {
            return true;  // Found it!
        }
        first = second;
        second = next;
    }
    
    return false;  // Reached a number greater than input, not found
}

// =============================================================================
// MAIN MENU
// =============================================================================
int main() {
    int choice;
    
    cout << "=== FIBONACCI SEQUENCE GENERATOR ===" << endl;
    cout << "1. Print First N Terms" << endl;
    cout << "2. Check if a Number is Fibonacci" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            int n;
            cout << "How many terms? ";
            cin >> n;
            printFibonacci(n);
            break;
        }
        case 2: {
            int num;
            cout << "Enter a number to check: ";
            cin >> num;
            
            if (isFibonacci(num)) {
                cout << num << " is a Fibonacci number." << endl;
            } else {
                cout << num << " is NOT a Fibonacci number." << endl;
            }
            break;
        }
        case 3:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    
    return 0;
} 