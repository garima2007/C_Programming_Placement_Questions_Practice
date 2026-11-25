#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char str[100], reverse[100];
    int i, n;
    int palindrome = 1;

    clock_t start, end;
    double time_taken;

    printf("Enter a string: ");
    scanf("%s", str);

    n = strlen(str);

    start = clock();

    for(i = 0; i < n; i++)
    {
        reverse[i] = str[n - i - 1];
    }

    reverse[n] = '\0';

    for(i = 0; i < n; i++)
    {
        if(str[i] != reverse[i])
        {
            palindrome = 0;
            break;
        }
    }

    end = clock();

    if(palindrome)
        printf("String is Palindrome\n");
    else
        printf("String is Not Palindrome\n");

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time = %.10f seconds\n", time_taken);

    return 0;
}

// Optimized form
#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char str[100];
    int left, right;
    int palindrome = 1;

    clock_t start, end;
    double time_taken;

    printf("Enter a string: ");
    scanf("%s", str);

    left = 0;
    right = strlen(str) - 1;

    start = clock();

    while(left < right)
    {
        if(str[left] != str[right])
        {
            palindrome = 0;
            break;
        }

        left++;
        right--;
    }

    end = clock();

    if(palindrome)
        printf("String is Palindrome\n");
    else
        printf("String is Not Palindrome\n");

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time = %.10f seconds\n", time_taken);

    return 0;
}
// it is checks half of the string 
Approach	           Time	    Extra Space	   Comparisons
Reverse + Compare	    O(n)	      O(n)	      Up to ~2n operations
Two Pointer	          O(n)	      O(1)        At most n/2 comparisons
