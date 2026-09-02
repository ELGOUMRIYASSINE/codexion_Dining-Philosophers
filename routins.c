#include "header.h"

void compile(t_coder *coder, t_c_table *table)
{
    set_long(&coder->coder_mutex, &coder->last_compile, get_time(MILIS));
    pthread_mutex_lock(&coder->left_dongle.dongle);
    print_log(coder, table, "has taken a dongle");  
    pthread_mutex_lock(&coder->right_dongle.dongle);
    print_log(coder, table, "has taken a dongle");
    
    print_log(coder, table, "is compiling");
    t_usleep(table->compile_time,table);
    coder->compiles_count += 1;

    if (table->required_compiles > 0 && coder->compiles_count >= table->required_compiles)
        set_bool(&coder->coder_mutex, &coder->finished, true);
    pthread_mutex_unlock(&coder->left_dongle.dongle);      
    pthread_mutex_unlock(&coder->right_dongle.dongle);
}

void debug(t_coder *coder, t_c_table *table)
{
    print_log(coder, table, "is debugin");
    t_usleep(table->debug_time, table);
}

void refactor(t_coder *coder, t_c_table *table)
{
    print_log(coder, table, "is refactoring");
    t_usleep(table->refactor_time, table);
}