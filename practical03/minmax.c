#include <stdio.h>

// Structure to hold min and max
struct Pair {
    int min;
    int max;
};

// Function to find min and max using divide and conquer
struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair minmax, mml, mmr;
    int mid;

    // If there's only one element
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    // If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    // If there are more than two elements
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);

    // Compare minimums and maximums of two parts
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;

    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;

    return minmax;
}

// Main function
int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    struct Pair minmax = getMinMax(arr, 0, arr_size - 1);
    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);
    return 0;
}
