#include "header.h"

void wait_all_coders(t_c_table *table)
{
    while (!get_bool(&table->table_mutex, &table->all_coders_on));
}

void* coders_simulation(void *coder_data)
{
    t_coder* coder;

    coder = (t_coder *)coder_data;
    wait_all_coders(coder->table);
    printf("I'm coder %d", coder->id);
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
        {
            pthread_create(&table->coders[i].coder, NULL, &coders_simulation, &table->coders[i]);
        }
    }
    // when all corders is ready
    set_bool(&table->table_mutex, &table->all_coders_on, true);
}