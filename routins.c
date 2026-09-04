#include "header.h"

bool cold_elapsed(t_dongle *dongle, t_c_table *table)
{
    long remain;
    remain = get_time(MILIS) - dongle->last_usage;
    return remain >= table->dongle_cooldown;
}

void aquire_dongles(t_dongle *coder_dongle, t_c_table *table)
{
    t_dongle *dongle;

    dongle = coder_dongle;
    pthread_mutex_lock(&dongle->dongle);
    while (!dongle->available || !cold_elapsed(dongle, table))
    {
        printf("-\n");   
        pthread_cond_wait(&dongle->cond, &dongle->dongle);
    }
    dongle->available = false;
    // dongle->last_usage = get_time(MILIS);
    pthread_mutex_unlock(&dongle->dongle);
}

void let_go(t_dongle *dongle)
{
    pthread_mutex_lock(&dongle->dongle);
    dongle->available = true;
    dongle->last_usage = get_time(MILIS);
    pthread_cond_broadcast(&dongle->cond);
    pthread_mutex_unlock(&dongle->dongle);
    
}


void compile(t_coder *coder, t_c_table *table)
{ 
    set_long(&coder->coder_mutex, &coder->last_compile, get_time(MILIS));
    aquire_dongles(coder->first_dongle, table);
    print_log(coder, table, "has taken a dongle");  
    aquire_dongles(coder->second_dongle, table);
    print_log(coder, table, "has taken a dongle");  
    // pthread_mutex_lock(&coder->first_dongle->dongle);
    // pthread_mutex_lock(&coder->second_dongle->dongle);
    // print_log(coder, table, "has taken a dongle");
    print_log(coder, table, "is compiling");
    t_usleep(table->compile_time,table);
    coder->compiles_count += 1;
    let_go(coder->first_dongle);
    let_go(coder->second_dongle);
    if (table->required_compiles > 0 && coder->compiles_count >= table->required_compiles)
        set_bool(&coder->coder_mutex, &coder->finished, true);
    // pthread_mutex_unlock(&coder->first_dongle->dongle);      
    // pthread_mutex_unlock(&coder->second_dongle->dongle);
}