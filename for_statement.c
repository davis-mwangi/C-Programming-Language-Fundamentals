#include<stdio.h>
int main(){
    int fahr;
    for(fahr = 0; fahr <=  300; fahr = fahr + 2){
        printf("%d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}