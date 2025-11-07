#include <stdio.h>
#include <stdlib.h>

/*
  min_max.c
  - Reads n from the user, then reads n integers and finds the minimum and maximum
    using the function `find_min_max`.
  - Example interaction:
      Enter number of elements: 5
      Enter 5 element(s): 3 1 4 1 5
      Min = 1
      Max = 5
*/

void find_min_max(const long long *arr, int n, long long *min, long long *max) {
    if (n <= 0 || !arr) return;
    long long mn = arr[0];
    long long mx = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < mn) mn = arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
    *min = mn;
    *max = mx;
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

    long long mn = 0, mx = 0;
    find_min_max(arr, n, &mn, &mx);

    printf("Min = %lld\n", mn);
    printf("Max = %lld\n", mx);

    free(arr);
    return 0;
}
