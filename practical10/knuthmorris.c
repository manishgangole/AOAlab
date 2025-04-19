#include <stdio.h>
#include <string.h>

// Function to build the longest prefix-suffix (LPS) array
void computeLPSArray(char* pattern, int* lps) {
    int len = 0;  // length of previous longest prefix suffix
    lps[0] = 0;   // lps[0] is always 0

    int i = 1;
    while (pattern[i] != '\0') {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMPSearch(char* text, char* pattern) {
    int M = strlen(pattern);
    int N = strlen(text);

    int lps[M];
    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern
    while (i < N) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter text: ");
    scanf("%s", text);
    printf("Enter pattern: ");
    scanf("%s", pattern);

    KMPSearch(text, pattern);

    return 0;
}
