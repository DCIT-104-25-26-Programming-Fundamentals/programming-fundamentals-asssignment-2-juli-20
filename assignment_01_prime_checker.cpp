// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

def is_prime(n):
    # Numbers less than 2 are NOT prime
    if n < 2:
        return False
    
    # Check if n is divisible by any number from 2 to n-1
    for i in range(2, n):
        if n % i == 0:
            return False  # Found a divisor - NOT prime
    
    return True  # No divisors found - IS prime

# Main block - asks user for input and displays result
def main():
    number = int(input("Enter a number: "))
    
    if is_prime(number):
        print(number, "is a prime number.")
    else:
        print(number, "is NOT a prime number.")

# This calls the main function when the program runs
main()