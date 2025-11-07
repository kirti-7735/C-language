#include <stdio.h>
#include <stdlib.h>

/* Recursive factorial using unsigned long long.
   Notes:
   - For n < 0: invalid.
   - 0! = 1.
   - Values n > 20 may overflow 64-bit unsigned long long.
*/

unsigned long long factorial(int n) {
    if (n <= 1) return 1ULL; // covers n == 0 and n == 1
    return (unsigned long long)n * factorial(n - 1);
}

int main(void) {
    int n;
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input. Expected an integer.\n");
        return 1;
    }

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    if (n > 20) {
        printf("Warning: %d! may overflow 64-bit unsigned long long; results will wrap.\n", n);
    }

    unsigned long long result = factorial(n);
    printf("%d! = %llu\n", n, result);
    return 0;
}
