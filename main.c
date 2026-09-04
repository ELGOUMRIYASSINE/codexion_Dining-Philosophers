#include "header.h"

int main(int arc, char *argv[])
{
    t_c_table table;
    // t_leak *g_tracker;
    int i = -1;
    if (arc != 9)
    {
        printf("wrong arguments count, 8 args needed\n");
        printf("example: ./program 4 10 2 5 3 3 7 [fifo or edf]");
        return 1;
    } else {
        parsing(&table, argv);
        init_utils(&table);
        pthread_mutex_init(&table.table_mutex, NULL);
        cycle_on(&table);
    }
}