#include "header.h"

int main(int arc, char *argv[])
{
    t_c_table table;
    t_leak *g_tracker;
    if (arc != 9)
    {
        printf("wrong arguments count, 8 args needed\n");
        printf("example: ./program 4 10 2 5 3 3 7 [fifo or edf]");
        return 1;
    } else {
        parsing(&table, argv, &g_tracker);
        printf("number of coders given is: %ld\n", table.number_of_coders);
        printf("schedular used is: %s\n", table.schedular);
    }
}