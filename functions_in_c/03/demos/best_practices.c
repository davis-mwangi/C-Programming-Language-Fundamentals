#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "wbc_lib.h"


// extern bool is_cleaning_machine;

void cleanup_coffee_machine(CoffeeMachine* machine, bool* is_cleaning_machine) {

    *is_cleaning_machine = true;

    machine->status = CLEANING_STATE;

    for (int i = 0; i < machine->duration; i++) {
        COLLECT_METRICS_API_CALL();
    }

    free(machine);

    is_cleaning_machine = false;
}

