#include <stdio.h>
#include <stdlib.h>

/*
  sum_two_arrays.c
  - Reads an integer n, then reads n integers for the first array and n integers for the second array.
  - Uses a function to compute element-wise sums and stores them in a third array.
  - Prints the third array.
  - Example interaction:
      Enter number of elements: 3
      Enter 3 element(s) of first array: 1 2 3
      Enter 3 element(s) of second array: 4 5 6
      Sum array: 5 7 9
*/

void sum_arrays(const long long *a, const long long *b, long long *c, int n) {
    for (int i = 0; i < n; ++i) c[i] = a[i] + b[i];
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input: expected an integer for number of elements.\n");
        return 1;
    }

    if (n <= 0) {
        printf("No elements to process (n <= 0).\n");
        return 0;
    }

    long long *a = malloc((size_t)n * sizeof(long long));
    long long *b = malloc((size_t)n * sizeof(long long));
    long long *c = malloc((size_t)n * sizeof(long long));
    if (!a || !b || !c) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(a); free(b); free(c);
        return 1;
    }

    printf("Enter %d element(s) of first array: ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%lld", &a[i]) != 1) {
            fprintf(stderr, "Invalid input: expected %d integers for first array.\n", n);
            free(a); free(b); free(c);
            return 1;
        }
    }

    printf("Enter %d element(s) of second array: ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%lld", &b[i]) != 1) {
            fprintf(stderr, "Invalid input: expected %d integers for second array.\n", n);
            free(a); free(b); free(c);
            return 1;
        }
    }

    sum_arrays(a, b, c, n);

    printf("Sum array: ");
    for (int i = 0; i < n; ++i) {
        if (i) printf(" ");
        printf("%lld", c[i]);
    }
    printf("\n");

    free(a); free(b); free(c);
    return 0;
}
