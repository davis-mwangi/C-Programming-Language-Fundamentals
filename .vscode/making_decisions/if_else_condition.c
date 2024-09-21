#include <stdio.h>
#include<string.h>

/*
Any value that evaluates to Zero(0) is false,
While any other number is true, 
thats why 
int num;
if(num = 6){ //will comile successfully
    
}
*/
int main(void){
    char password[20];

    printf(" Please enter the Password: ");
    scanf("%19s", password);

    if(strcmp(password, "Pluralsight") == 0){
        printf(" Correct password!");
    }else {
        printf(" Wrong password :-( \n");
    }

    return 0;
}