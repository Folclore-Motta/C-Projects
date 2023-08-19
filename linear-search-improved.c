#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/* A program that generates a random array of specifed sized and them sort them using
sort, bubble and merge*/

//#define TEST_NOW true

void create_random_values_into_array(int *array_addres, int array_size, int range_of_value)
{
    int current_index, random_number;
    srand(time(NULL));

    for (current_index = 0; current_index < array_size; current_index++)
    {
        random_number = rand() % range_of_value;
        array_addres[current_index] = random_number;
    }
}

void linear_order_asc_and_desc_array(
    int *array_addres, int size, bool is_cresent_param)
{
    bool swap_now = false;
    int current_idx, next_idx, aux, first_value, second_value;

    for (current_idx = 0; current_idx < size; current_idx++)
    {
        for (next_idx = current_idx+1; next_idx < size; next_idx++)
        {
            first_value = array_addres[current_idx];
            second_value = array_addres[next_idx];

            if (is_cresent_param)
            {
                swap_now = first_value > second_value; 
            }
            else
            {
                swap_now = first_value < second_value;
            }
         
            if (swap_now)
            {
                aux = first_value;
                array_addres[current_idx] = second_value;
                array_addres[next_idx] = aux;
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3){
        fprintf(stderr, "Wrong usage please specify an ordem 1:Anscending 0:descending\n");
        return 1;
    }

    int total_values = atoi(argv[1]);
    int current_index;
    int array[total_values];

    // Generate randomic numbers between 0 and 99
    create_random_values_into_array(array, total_values, 100);
    linear_order_asc_and_desc_array(array, total_values, atoi(argv[2]));
    // Arrange the values depending of the value passed by the user

    
    for (current_index = 0; current_index<total_values; current_index++)
    {
        printf("%d, ", array[current_index]);
    }
    printf("\n");
    return 0;
}
