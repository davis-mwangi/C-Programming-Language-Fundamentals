#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check_strings_equal(const char *str1, const char *str2)
{
    return !strcmp(str1, str2);
}
int main(void)
{
    const char *my_name = "David";

    // Calling user-defined function
    bool names_equal = check_strings_equal(my_name, "37");

    printf("These names are equal: %s \n", names_equal ? "true" : "false");

    return 0;
}