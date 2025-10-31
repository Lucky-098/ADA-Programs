#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search function
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // return index if found
        }
    }
    return -1; // not found
}

// Generate random array
void generateRandomArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

int main() {
    int key = -1; // Aisi value jo array me chance kam hai
    int result;
    int sizes[] = {1000, 2000, 5000, 10000, 20000, 50000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(0)); // har run par alag sequence par random number generate honge

    printf("n\tTime_taken(seconds)\n");
    printf("---------------------------------\n");

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];

       
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed for size %d\n", n);
            exit(1);
        }

        generateRandomArray(arr, n);

        // measure time
        clock_t start = clock();
        for (int i = 0; i < 1000; i++) { 
            result = linearSearch(arr, n, key);
        }
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000;

        printf("%d\t%f\n", n, time_taken);

     
        free(arr);
    }

    return 0;
}
