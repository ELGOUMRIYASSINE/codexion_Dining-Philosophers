#include "header.h"

void set_bool(t_mtx *mutex, bool *dest, bool value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}

bool get_bool(t_mtx *mutex, bool* value)
{
    bool rest;
    pthread_mutex_lock(mutex);
    rest = *value; 
    pthread_mutex_unlock(mutex);
    return (rest);
}

long get_long(t_mtx *mutex, long* value)
{
    long rest;
    pthread_mutex_lock(mutex);
    rest = *value;
    pthread_mutex_unlock(mutex);
    return (rest);
}

void set_long(t_mtx *mutex, long* dest, long value)
{
    pthread_mutex_lock(mutex);
    *dest = value; 
    pthread_mutex_unlock(mutex);
}

bool get_end_simulation(t_c_table *table)
{
    return get_bool(&table->table_mutex, &table->end);
}

