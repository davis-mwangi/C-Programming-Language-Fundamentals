#include<stdio.h>
#include<string.h>

struct Date{
    char month[3];
    int year;
} Date;

struct Person {
    struct Date birth;
    struct Date death;
    char name[32];
    char country[32];
    char KnownFor[32];
} Person;

int main(){
    struct Person outlier[4];
    int count;

    strcpy(outlier[0].name,  "Johannes Gutenberg");
    
}