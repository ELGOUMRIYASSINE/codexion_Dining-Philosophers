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

    // set last compile time
    // start simulation
    while (!get_end_simulation(coder->table))
    {
        // is i compiled all times i need
        if ((coder->compiles_count == coder->table->required_compiles)) 
            break;
        
        // compile time
        // print_log(coder, &coder->table, "is compiling");
        compile(coder, coder->table);

        // debug time
        print_log(coder, coder->table, "is debugin");
        t_usleep(coder->table->debug_time, coder->table);

        // refactor_time
        print_log(coder, coder->table, "is refactoring");
        t_usleep(coder->table->refactor_time, coder->table);

    }
    // printf("coder %d created\n", ((t_coder *)coder_data)->id);
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
    table->start_time = get_time(MILIS);
    set_bool(&table->table_mutex, &table->all_coders_on, true);
    i = -1; 
    while (++i < table->number_of_coders)
        pthread_join(table->coders[i].coder, NULL);
    
}