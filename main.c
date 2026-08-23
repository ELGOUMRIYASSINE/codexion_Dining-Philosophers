#include "header.h"


int main(int arc, char *argv[])
{
    t_c_table table;

    if (arc != 9)
    {
        printf("wrong arguments count, 8 args needed\n");
        printf("example: ./program 4 10 2 5 3 3 7 [fifo or edf]");
        return 1;
    } else {
        parsing(&table, argv);
        printf("number of coders given is: %ld\n", table.number_of_coders);
        printf("schedular used is: %s\n", table.schedular);
    }
}