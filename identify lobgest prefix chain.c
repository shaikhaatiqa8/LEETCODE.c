#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char strs[][200], int strsSize) {
    static char prefix[200];
    if (strsSize == 0) return "";

    strcpy(prefix, strs[0]); // Start with the first string as the prefix

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // Compare characters until they differ or one string ends
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0'; // Cut the prefix at the mismatch point
    }

    return prefix;
}

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    char strs[200][200];
    for (int i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", strs[i]);
    }

    printf("Longest Common Prefix: \"%s\"\n", longestCommonPrefix(strs, n));
    return 0;
}
