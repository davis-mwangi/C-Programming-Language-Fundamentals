#include <stdio.h>
#include <stdlib.h>

/* Function Declarations*/
void print_int_by_reference(int *number_ptr);
void print_int_by_value(int number);

void malloc_int_dangerous(int *number_ptr);
void malloc_int_safe(int **number_ptr);

int main(void)
{

    // Give example of passing an int via a pointer instead of by value
    int my_number = 10;

    print_int_by_value(my_number);

    print_int_by_reference(&my_number);

    printf("The address printed above should be different! ^^ \n\n\n");

    int *number_ptr = &my_number;

    printf(" 'number_ptr' address before malloc: &p\n", number_ptr);

    /*
     1. Create function that takes in a pointer to an int, attempts to malloc memory for it
     and return the pointer,

     this will not work(memory leak will occur...because the pointer passed in points to memory
      on the stack.)
    */
    malloc_int_dangerous(number_ptr);

    printf("Original 'number_pointer' address after dangerous malloc: %p\n", number_ptr);
    printf("The above address for 'number_ptr' does not change!\n ");
}

/*
Function definitions
*/

// Takes in an integer and prints ot to the console
void print_int_by_reference(int *number_ptr)
{
    printf("Printing Int =>> Address :  %p | Value:  %d\n", number_ptr, *number_ptr);
}

/* The 'number' argument below is copied into the function scope*/
void print_int_by_value(int number)
{
    printf("Printing Int =>> Adress:  %p | Value:  %d\n", &number, number);
}

/*This will not work and will cause memory leak because 'number_ptr' is passsed by value */
void malloc_int_dangerous(int *number_ptr)
{
    number_ptr = (int *)malloc(sizeof(int));
    printf("[malloc_int_dangerous] => 'number_ptr' address after dangerous malloc : %p\n", number_ptr);
    printf("[malloc_int_dangerous] => ^^ address space  marks a memory-leaked block!\n\n");

    /* 'number_ptr' now goes out of scope and you have memory leak */
}

/*This will work nicely and will not cause memory leak as long as the caller of this function frees the memory*/
void malloc_int_safe(int **number_ptr)
{
    *number_ptr = (int *)malloc(sizeof(int));
}
