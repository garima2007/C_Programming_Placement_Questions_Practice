// Write a program to print the sum of all odd digits and some of all even digits of a number?
#include <stdio.h>
int main()
{
    int x;
    printf("enter a number: ");
    scanf("%d", &x);
    int odd_sum = 0;
    int even_sum = 0;
    int digit;
    while(x != 0)
    {
        digit = x % 10;
    
    if( digit % 2 == 0)
    {
        even_sum = even_sum + digit;
    }
    else
    {
        odd_sum = odd_sum + digit;
    }
    x = x / 10;
}
printf("sum of even digits = %d\n", even_sum);
printf("sum of odd digits = %d" , odd_sum);

return 0;
}
// Time Complexity: O(log n) because we remove one digit in every iteration.
// Space Complexity: O(1) because we use only a fixed number of variables.
