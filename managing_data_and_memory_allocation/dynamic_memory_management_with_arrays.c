#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_SIZE 1000

double get_random_number();

void gather_metrics(size_t size, double *metric_arrr);

int main(int argc, char *argv[])
{
    int array_size = DEFAULT_SIZE;

    if (argc > 1)
    {
        array_size = strtol(argv[1], NULL, 10);
    }

    // Dynamically allocated Memory
    double *heat_distrbution_metrics = (double *)malloc(array_size * sizeof(double));
    double *grinder_metrics = (double *)malloc(array_size * sizeof(double));
    double *pour_metrics = (double *)malloc(array_size * sizeof(double));

    /*There is a possiblity malloc can return null if there is no enough memory
    We need to make the checks and set o DEFAULT_SIZE*/
    if (!heat_distrbution_metrics)
    {
        heat_distrbution_metrics = (double *)malloc(DEFAULT_SIZE * sizeof(double));
    }

    if (!grinder_metrics)
    {
        grinder_metrics = (double *)malloc(DEFAULT_SIZE * sizeof(double));
    }

    if (!pour_metrics)
    {
        pour_metrics = (double *)malloc(DEFAULT_SIZE * sizeof(double));
    }

    double *metrics_matrix[3] = {
        heat_distrbution_metrics,
        grinder_metrics,
        pour_metrics};

    for (int i = 0; i < 3; i++)
    {
        gather_metrics(array_size, metrics_matrix[i]);
    }
    // Print out the details of row and column
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < array_size; j++)
        {
            printf("Row/Col: %d/%d ==> Value:  %f\n", i + 1, j + 1, metrics_matrix[i][j]);
        }
    }

    // Free Memory
    for (int i = 0; i < 3; i++)
    {
        free(metrics_matrix[i]);
    }

    /*
    Instead of callling gather_metrics 3 times, we can use a 2-D array

    gather_metrics(array_size, heat_distrbution_metrics);
    gather_metrics(array_size, grinder_metrics);
    gather_metrics(array_size, pour_metrics);

    */

    return 0;
}

void gather_metrics(size_t size, double *metric_arrr)
{
    for (int i = 0; i < size; i++)
    {
        metric_arrr[i] = get_random_number();
    }
}

double get_random_number()
{
    return rand() / (RAND_MAX / 2.5);
}
