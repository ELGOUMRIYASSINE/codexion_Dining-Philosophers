#include "header.h"

void wait_all_coders(t_c_table *table)
{
    printf("entered...");
    while (!get_bool(&table->table_mutex, &table->all_coders_on))
        printf("waiting\n");
}

void* coders_simulation(void *coder_data)
{
    t_coder* coder;
    coder = (t_coder *)coder_data;
    wait_all_coders(coder->table);
    printf("coder %d created\n", ((t_coder *)coder_data)->id);
    return (NULL);
}

void cycle_on(t_c_table* table)
{
    int i;

    i = -1;
    if (table->number_of_coders == 1) {
        return;
    } else {
        while (++i < table->number_of_coders)
            pthread_create(&table->coders[i].coder, NULL, &coders_simulation, &table->coders[i]);
    }
    set_bool(&table->table_mutex, &table->all_coders_on, true);
    i = 0; 
    while (++i < table->number_of_coders)
        pthread_join(table->coders[i].coder, NULL);
    printf("finished\n");
}