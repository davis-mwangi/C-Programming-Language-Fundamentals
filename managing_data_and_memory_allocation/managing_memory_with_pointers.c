#include <stdio.h>
#include <string.h>
/*
Globals
*/
int metric_count = 0;

/*
Functions/ Structures Declarations
*/

/*Define a simple Metric type for sending off the amount of the power used by the CoffeMachine for a given sequence*/
typedef struct Metric
{
    int sequence_number;
    float power_used;
} Metric;

/*Define our CoffeMAchine type!*/
typedef struct CoffeMachine
{
    int (*pour)(int, struct CoffeMachine *);
    Metric **metrics;
    int pour_duration;
} CoffeeMachine;

// CoffeeMachine Create/Destroy API
int init_coffee_machine(CoffeeMachine **);
void cleanup_machine(CoffeeMachine *);

/*Different PourHandler Function Declarations*/
int pour_decaf(int, CoffeeMachine *);
int pour_classic(int, CoffeeMachine *);
int pour_rich(int, CoffeeMachine *);

/*Metric API*/
Metric *create_metric(float);
int send_metrics(Metric **, size_t metric_size);

// This 'main' function is here to simply test and make use of the API functions below

int main(int argc, char *argv[])
{
    // Instantiate a test Coffee machine
    CoffeeMachine *my_machine;

    if (init_coffee_machine(&my_machine))
    {
        printf("System does not have emough memory to allocate a Coffe MAchine structure");
        return 1;
    }

    printf("\nMAchine Activated\n");

    char *user_pour_mode = argv[1];
    int duration = strtol(argv[2], NULL, 10);

    my_machine->pour_duration = duration;

    // A pour mode(one of 'decaf', 'rich', or 'classic') is required along with a pour duration
    if (argc > 2)
    {
        // Set the 'pour' function pointer based on the pour mode argument
        if (!strcmp("decaf", user_pour_mode))
        {
            my_machine->pour = pour_decaf;
        }
        else if (!strcmp("rich", user_pour_mode))
        {
            my_machine->pour = pour_rich;
        }
        else
        {
            my_machine->pour = pour_classic;
        }
    }
    else
    {
        printf("Please pass pour mode and pour duration arguments!");
        return 1;
    }
}

// Dynamically allocates enough memory for a CoffeeMAchine type
int init_coffee_machine(CoffeeMachine **machine)
{
    if ((*machine = (CoffeeMachine *)malloc(sizeof(CoffeeMachine))))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Pours a decaf cup of Coffee
int pour_decaf(int duration, CoffeeMachine *machine)
{
    int start = 0;
    Metric **metrics_ptr = (Metric **)malloc(duration * sizeof(Metric));
    machine->metrics = metrics_ptr;

    while (start < duration)
    {
        // Do some Processing of pouring here...
        float power_used = 4.4;

        Metric *metric = create_metric(power_used);
        *(metrics_ptr + start) = metric;

        start++;
    }

    return 0;
}

//Frees up resources that were allocated in relation to a CoffeMachine
void cleanup_machine(CoffeeMachine *machine){
    //Free individual metrics
    for(int i = 0; i < machine->pour_duration; i++){
        Metric  *metric =  machine->metrics[i];
        printf("\n Freeing Metric At Count:  %d\n", metric->sequence_number);
        free(metric);
    }
    free(machine->metrics);
    free(machine);
}