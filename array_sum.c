#include <stdio.h>
#include <stdlib.h>

/*
  array_sum.c
  - Reads n from the user, then reads n integers and computes their sum using a function.
  - Uses dynamic allocation so large n values are supported.
  - Example input on one line: 4 1 2 3 4
*/

long long sumArray(const long long *arr, int n) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) sum += arr[i];
    return sum;
}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input: expected an integer for number of elements.\n");
        return 1;
    }

    if (n <= 0) {
        printf("No elements to sum (n <= 0).\n");
        return 0;
    }

    long long *arr = malloc((size_t)n * sizeof(long long));
    if (!arr) {
        fprintf(stderr, "Allocation failed.\n");
        return 1;
    }

    printf("Enter %d element(s): ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%lld", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input: expected %d integers.\n", n);
            free(arr);
            return 1;
        }
    }

    long long total = sumArray(arr, n);
    printf("Sum = %lld\n", total);

    free(arr);
    return 0;
}
