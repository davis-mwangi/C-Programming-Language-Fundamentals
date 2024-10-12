typedef struct CoffeeMachine
{
    int status;
    char *serial_number;
    int duration;
} CoffeeMachine;

CoffeeMachine *make_coffee_machine(int status, char *serial_number, int duration);
