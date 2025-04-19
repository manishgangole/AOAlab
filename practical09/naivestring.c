#include <stdio.h>
#include <string.h>

void naiveStringMatching(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    // Loop to go through text
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        // Check if pattern matches
        while (j < m && text[i + j] == pattern[j])
            j++;

        if (j == m) // Match found
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);

    naiveStringMatching(text, pattern);

    return 0;
}
