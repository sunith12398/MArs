#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for qsort)
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Muchiko Filter (Moving Average)
void muchikoFilter(int data[], int size, int windowSize, int result[]) {
    int sum, count;
    for (int i = 0; i < size; i++) {
        sum = 0;
        count = 0;
        for (int j = i - windowSize / 2; j <= i + windowSize / 2; j++) {
            if (j >= 0 && j < size) {
                sum += data[j];
                count++;
            }
        }
        result[i] = sum / count; // Average
    }
}

// Sanchiko Filter (Median Filter)
void sanchikoFilter(int data[], int size, int windowSize, int result[]) {
    int window[windowSize];
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = i - windowSize / 2; j <= i + windowSize / 2; j++) {
            if (j >= 0 && j < size) {
                window[count++] = data[j];
            }
        }
        qsort(window, count, sizeof(int), compare);
        result[i] = window[count / 2]; // Median
    }
}

// Hybrid Filter (Moving Average + Median)
void hybridFilter(int data[], int size, int windowSize, int result[]) {
    int temp[size];
    muchikoFilter(data, size, windowSize, temp); // Apply Muchiko
    sanchikoFilter(temp, size, windowSize, result); // Apply Sanchiko
}

int main() {
    int data[] = {5, 8, 6, 10, 15, 14, 20, 30, 25, 50, 45, 40, 38, 35, 33};
    int size = sizeof(data) / sizeof(data[0]);
    int windowSize = 3; // Window size for filters

    int muchikoResult[size];
    int sanchikoResult[size];
    int hybridResult[size];

    // Apply Filters
    muchikoFilter(data, size, windowSize, muchikoResult);
    sanchikoFilter(data, size, windowSize, sanchikoResult);
    hybridFilter(data, size, windowSize, hybridResult);

    // Display Results
    printf("Original Data:  ");
    for (int i = 0; i < size; i++) printf("%d ", data[i]);
    printf("\n");

    printf("Muchiko Filtered: ");
    for (int i = 0; i < size; i++) printf("%d ", muchikoResult[i]);
    printf("\n");

    printf("Sanchiko Filtered: ");
    for (int i = 0; i < size; i++) printf("%d ", sanchikoResult[i]);
    printf("\n");

    printf("Hybrid Filtered: ");
    for (int i = 0; i < size; i++) printf("%d ", hybridResult[i]);
    printf("\n");

    return 0;
}
