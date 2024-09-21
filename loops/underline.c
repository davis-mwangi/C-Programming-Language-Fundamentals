#include<stdio.h>
#include<string.h>

int main(void){
    /*String to underline*/
    char str [] = "David is learning C";

    /*Print the underline*/
    printf("%s \n", str);

    int len = strlen(str);
    for(int i=0;i< len; i++){
        putchar('-');
    }
    putchar('\n');

    return 0;

}