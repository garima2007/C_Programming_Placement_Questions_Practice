// Question 2
// Study and implement the tower of hanoi problem?
// Identify 
// Complexity 
// Real world use
#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    printf("Move disk %d from %c to %c\n", n, source, destination);

    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
// Time Complexity = O(2ⁿ)
// Tower of Hanoi is a recursive problem in which we move n disks from a source rod to a destination rod using an auxiliary rod, without placing a larger disk over a smaller disk. Its minimum number of moves is 2ⁿ − 1, so its time complexity is O(2ⁿ), and its recursive space complexity is O(n)
