#include <stdio.h>

int set[100], solution[100];
int n, target;

void displaySubset(int k) {
    printf("Subset: ");
    for (int i = 0; i < k; i++) {
        if (solution[i])
            printf("%d ", set[i]);
    }
    printf("\n");
}

void sumOfSubsets(int k, int currentSum, int remaining) {
    solution[k] = 1; // include element
    if (currentSum + set[k] == target)
        displaySubset(k + 1);
    else if (currentSum + set[k] + set[k + 1] <= target)
        sumOfSubsets(k + 1, currentSum + set[k], remaining - set[k]);

    if (currentSum + remaining - set[k] >= target && currentSum + set[k + 1] <= target) {
        solution[k] = 0; // exclude element
        sumOfSubsets(k + 1, currentSum, remaining - set[k]);
    }
}

int main() {
    int total = 0;

    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter elements (positive integers):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
        total += set[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    if (total < target) {
        printf("No solution possible. Sum of all elements is less than target.\n");
        return 0;
    }

    sumOfSubsets(0, 0, total);

    return 0;
}
