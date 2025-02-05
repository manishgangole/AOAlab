#include <stdio.h>
// Function to swap two elements
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}
// Partition function
int partition(int arr[], int low, int high) {
 int pivot = arr[high]; // Pivot element
 int i = low - 1; // Index of smaller element
 for (int j = low; j < high; j++) {
 // If current element is smaller than or equal to the pivot
 if (arr[j] <= pivot) {
 i++;
 swap(&arr[i], &arr[j]);
 }
 }
 swap(&arr[i + 1], &arr[high]); // Place pivot at the right position
 return i + 1;
}
// QuickSort function
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 // Partition the array
 int pi = partition(arr, low, high);
 // Recursively sort the two halves
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
int main() {
 int n;
 // Input the size of the array
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 int arr[n];
 // Input the elements of the array
 printf("Enter %d elements:\n", n);
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
// Perform quick sort
 quickSort(arr, 0, n - 1);
 // Output the sorted array
 printf("Sorted array: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 return 0;
}
