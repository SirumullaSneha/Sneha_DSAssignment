#include <stdio.h>

// Function prototype
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod);           

// Function to solve Tower of Hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    
    // Move (n-1) disks from A to B using C as auxiliary
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    
    // Move nth disk from A to C
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    // Move (n-1) disks from B to C using A as auxiliary
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}
