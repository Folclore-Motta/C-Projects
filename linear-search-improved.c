#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

/* A program that generates a random array of specifed sized and them sort them using
sort, bubble and merge*/

//#define TEST_NOW true
#define LEN 50

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
    
    FILE *file_output;
    int current_index;
    char caracter;
    
    // argv[0] filename
    // argv[1] total values
    // argv[2] filename

    if (argc != 3){
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    
    int total_values = atoi(argv[1]);
    int array[total_values];

    create_random_values_into_array(array, total_values, 100);

    if ((file_output = fopen(argv[2], "w")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    for (current_index = 0; current_index<total_values; current_index++)
    {
        fprintf(file_output, "%d\n", array[current_index]);
    }
        
    // Generate randomic numbers between 0 and 99
    

    if (fclose(file_output) != 0)
    {
        fprintf(stderr, "Error in closing file!\n");
    }
    return 0;
}
