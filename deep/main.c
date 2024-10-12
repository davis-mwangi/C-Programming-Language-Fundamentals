#include<stdio.h>
#include "orders.h"

int main(int argc, char *argv[]){
    double order_subtotal = 50.00;

    double grand_total = calculate_order_total(order_subtotal);
    printf("Grand Total: %1f", grand_total);
}