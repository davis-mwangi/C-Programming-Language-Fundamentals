#include <stdio.h>

/*
Switch in C only works with integral numbers like int, char and
not strings, floatig points numbers etc, will have to use the if...else...
statements in this case
*/
int main(void)
{
    int number;

    printf("Please enter an integer number: ");
    scanf("%d", &number);

    switch (number)
    {
    case 1:
        printf(" You entered one. \n");
        break;
    case 10:
        printf(" You entered ten\n");
        break;

    case 64:
        printf(" You entered sixty four\n");
        break;
    default:
        printf(" You entered a number different from 1, 10 and 64");
        break;
    }
}