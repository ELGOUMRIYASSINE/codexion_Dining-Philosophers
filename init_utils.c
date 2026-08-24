#include "header.h"

int fill_coders(t_c_table* table)
{
    int i;
    t_coder* coder;
    
    i = -1;
    while (++i < table->number_of_coders)
    {
        coder = &table->coders[i];
        coder->id = i;
        coder->compiles_count = 0;
        coder->table = table;
        if (i == 0)
        {
            table->coders[i].left_dongle = table->dongles[table->number_of_coders - 1];
            table->coders[i].right_dongle = table->dongles[i];
        } else {
            table->coders[i].left_dongle = table->dongles[i - 1];
            table->coders[i].right_dongle = table->dongles[i];
        }
    }
}

int fill_dongles(t_c_table* table)
{
    int i;

    i = -1;
    while (++i < table->number_of_coders)
    {
        pthread_mutex_init(&table->dongles[i].dongle, NULL);
        table->dongles[i].dongle_id = i;
    } 
}

int init_utils(t_c_table* table)
{
    table->coders = malloc(sizeof(t_coder) * table->number_of_coders);
    table->dongles = malloc(sizeof(t_dongle) * table->number_of_coders);
    if (!table->dongles || !table->coders)
        return (2);
    else {
        fill_dongles(table);
        fill_coders(table);
    }
}
