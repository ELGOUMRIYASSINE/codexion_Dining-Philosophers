#include "header.h"


long get_time(t_time time_type)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    if (time_type == SECOND)
        return (tv.tv_sec +  ((tv.tv_usec / 1000) / 1000));
    if (time_type == MILIS)
        return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    if (time_type == MICROS)
        return ((tv.tv_sec * 1000000) + tv.tv_usec);
    return (1);
}

void    t_usleep(unsigned long ms, t_c_table *data)
{
    long start;

    start = get_time(MILIS);
    while (get_time(MILIS) - start < ms)
    {
        if (get_end_simulation(data))
            break;
        usleep(10000);
    }
}