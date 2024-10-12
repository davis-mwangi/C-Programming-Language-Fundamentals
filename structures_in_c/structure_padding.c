#include <stdio.h>

struct
{
    char sponsor;
    char designer;
    int number;
} smallShirt; // 8 -6 = 2 bytes  of RAM wasted

struct
{
    char sponsor; // 1
    int number; //4
    char designer; // 1
} largeShirt; // 12-6 = 6 bytes of RAM wasted

int main()
{
    printf("\n\tSmall Shirt: %ld bytes", sizeof(smallShirt));
    printf("\n\tLarge Shirt:  %ld  bytes\n\n", sizeof(largeShirt));
}