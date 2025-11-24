#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;

    // Taking input for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Taking array elements input
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble sort algorithm
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Printing sorted array
    printf("Sorted array in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}