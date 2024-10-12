#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x = 10;
    int y = 20;
    printf("Initial values: \n x=%d; y = %d \n", x, y);

    /*Invoke Swapping*/
    swap(&x, &y);

    printf("Values after calling swap: \n x = %d; y = %d", x, y);

    return 0;
}