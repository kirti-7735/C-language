#include <stdio.h>
#include <stdlib.h>

/*
  linear_search.c
  - Reads n, then n integers, then a key to search.
  - Uses a function `linear_search` to find the first index of key (0-based).
  - Prints the index if found, otherwise indicates not found.
*/

int linear_search(const long long *arr, int n, long long key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) return i;
    }
    return -1;
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

    long long *arr = malloc((size_t)n * sizeof(long long));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed.\n");
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

    long long key;
    printf("Enter element to search: ");
    if (scanf("%lld", &key) != 1) {
        fprintf(stderr, "Invalid input for key.\n");
        free(arr);
        return 1;
    }

    int idx = linear_search(arr, n, key);
    if (idx == -1) {
        printf("%lld not found in the array.\n", key);
    } else {
        printf("%lld found at index %d (0-based).\n", key, idx);
    }

    free(arr);
    return 0;
}
