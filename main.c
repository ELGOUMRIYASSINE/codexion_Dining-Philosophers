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
        // printf("ALl is filled\n");
        while (++i < table.number_of_coders)
        {
            printf("coder id: %d\n", table.coders[i].id);
            printf("left dongle: %d\n", table.coders[i].left_dongle.dongle_id);
            printf("right dongle: %d\n", table.coders[i].right_dongle.dongle_id);
        }
    }
}