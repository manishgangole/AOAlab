#include <stdio.h>
#include <string.h>

// Function to find LCS length and display it
void lcs(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int L[m + 1][n + 1];

    // Build LCS table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // Print length of LCS
    printf("\nLength of LCS: %d\n", L[m][n]);

    // Recover the LCS string
    int index = L[m][n];
    char lcsStr[index + 1];
    lcsStr[index] = '\0'; // null terminate

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr[--index] = X[i - 1];
            i--; j--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcsStr);
}

int main() {
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    lcs(X, Y);

    return 0;
}
