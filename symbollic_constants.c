#include<stdio.h>

#define LOWER 0 //Lower limit of the table
#define UPPER 300 //Upper Limit
#define STEP 20 //Step Size

int main(){
    int farh;
    for(farh = LOWER; farh <=  UPPER; farh =  farh + STEP){
        printf("%4d %6.1f\n", farh,  (5.0/9.0) * (farh -  32));
    }
}
