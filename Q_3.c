// Question 3:
// Find whether the substring is part of main string.
// Constraints:
// In O(n) times
#include <stdio.h>
#include <string.h>

void computeLPS(char pattern[], int m, int lps[])
{
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];

    computeLPS(pattern, m, lps);

    int i = 0;  // text
    int j = 0;  // pattern

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            return 1;   // substring found
        }
        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return 0;   // substring not found
}

int main()
{
    char text[100], pattern[100];

    printf("Enter main string: ");
    scanf("%s", text);

    printf("Enter substring: ");
    scanf("%s", pattern);

    if (KMP(text, pattern))
        printf("Substring is present.\n");
    else
        printf("Substring is not present.\n");

    return 0;
}
// Why KMP?
// The important part is the LPS array (Longest Proper Prefix which is also a Suffix). When a mismatch occurs, instead of starting the substring comparison from the beginning, KMP uses the LPS array to decide where to continue
