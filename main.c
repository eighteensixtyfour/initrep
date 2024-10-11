#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void bubbleSort(int* arr, int size);

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("usage: %s -f [num 0-3]\n", argv[0]);
        return 0;
    }
    int c;
    char fval;
    while ((c = getopt(argc, argv, "f:")) != -1) {
        if (c == 'f') {
           fval = optarg[0];
        }
        else { // opt == '?'
            printf("usage: %s -f [num 0-3]\n", argv[0]);
            return 0;
        }
    }

    int n;
    printf("n: "); scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    if (fval == '2' || fval == '3') {
        bubbleSort(arr, n);
    }
    if (fval == '0' || fval == '2') {
        for (int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else if (fval == '1' || fval == '3') {
        for (int i = n - 1; i >= 0; --i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    free(arr);
    return 0;
}

void bubbleSort(int* arr, int size) {
    int t;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = size - 1; j > i; --j) {
            if (arr[j] < arr[j - 1]) {
                t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
            }
        }
    }
}
