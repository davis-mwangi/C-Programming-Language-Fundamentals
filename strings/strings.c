#include <stdio.h>
#include <string.h>
int main(void)
{
    // String in C:
    // Null- terminated contigious sequence of chars
    printf("What's your name ?:");

    char name[40];

    scanf("%39s", name); // 40th character is a null

    printf("\n");

    /*
 Copying Strings

 msg = name + "is" + "learning C."
*/
    char msg[100];

    /* 
    Can lead to memory overflow

    strcpy(msg, name);
    strcat(msg, " is ");
    strcat(msg, "learning C.");

    */

    //Safe functions
    strcpy_s(msg, sizeof(msg), name);
    strcat_s(msg, sizeof(msg), " is ");
    strcat_s(msg, sizeof(msg), "learning C.");

    int msgLen = strlen(msg);
    int mgsSize = sizeof(msg);

    printf("Nice to  meet you, %s!\n", msg);

    printf("\nLength =  %d; Size = %d", msgLen, mgsSize);

    return 0;
}