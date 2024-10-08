#include <stdio.h>
#include <stddef.h>

/* Custom type definition */
typedef struct Grade
{
    char letter;
    int rank;
} Grade;

int main(int argc, char *argv[])
{
    // Declare and initialize struct on the stack
    const Grade student_grade = {'A', 96};

    // Read values from a struct's members
    printf("\n\nLetter:: \t\t\t\t\t\t%c\n", student_grade.letter);
    printf("Rank:: \t\t\t\t\t\t%d\n", student_grade.rank);

    // Get byte size of struct members and total byte size of struct
    const size_t letter_byte_size = sizeof(student_grade.letter);
    const size_t rank_byte_size = sizeof(student_grade.rank);

    printf("Size of student_grade.letter is:\t\t%zu", letter_byte_size);
    printf("Size of student_grade.rank is: \t\t\t%zu", rank_byte_size);

    const size_t student_grade_byte_size = sizeof(student_grade);
    printf("Total size of student_grade is bytes:\t\t%zu\n\n", student_grade_byte_size);

    // Calculate necessary padding via sizes of struct members
    const size_t total_padding_in_grade_struc = student_grade_byte_size - (letter_byte_size + rank_byte_size);
    printf("Total padding of Grade struct in bytes:\t\t%zu\n\n", total_padding_in_grade_struc);

    // Reveal memory address positions of struct members
    printf("Address of b:\t\t\t\t\t\t%p\n", &student_grade.letter);
    printf("Address of a:\t\t\t\t\t\t%p\n", &student_grade.rank);

    // Calculate padding via memory offsets using the <stddef.h> "offset"macro
    const size_t letter_offset = offsetof(Grade, letter);
    const size_t rank_offset = offsetof(Grade, rank);
    const size_t padding = rank_offset - (letter_offset + letter_byte_size);

    printf("Letter byte offset is:\t\t\t\t\t%zu\n\n", letter_offset);
    printf("Rank byte offset is:\t\t\t\t\t%zu\n\n", rank_offset);
    printf("Total padding of Grade struct in bytes is :\t\t\t\t\t%zu\n\n", padding);
    printf("-------------------------------------------------------\n");
    printf("| Letter:  %zu | Padding:  %zu | Rank: %zu |\n", letter_byte_size, padding, rank_byte_size);
    printf("----------------------------------------------------------");

    return 0;
}
