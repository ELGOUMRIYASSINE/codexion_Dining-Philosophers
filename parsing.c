#include "header.h"

int check_values(char *arguments[], int i)
{
    if (i == 1 || i == 2 || i == 6)
    {   
        if (atoi(arguments[i]) <= 0)
            return (0);
    }
    if (i == 3 || i == 4 || i == 5 || i == 7)
    {
        if (atoi(arguments[i]) < 0)
            return (0);
    }
    return (1);
}

int check_args(char *argv[])
{
    int     i;
    char    *arg;
    int     j;
    
    i = 1;
    while (i < 9)
    {
        j = 0;
        if (i == 8 && (!memcmp(argv[i], "fifo", 4) & !memcmp(argv[i], "edf", 3)))
            return (0);
        else if (i != 8) 
        {
            while (argv[i][j])
            {
                if (!isdigit((char) argv[i][j]))
                    return (0); 
                j++;
            }
        }
        if (!check_values(argv, i))
            return (0);
        i++;
    }

    return (1);
}

void* fill_table(t_c_table *table, char *argv[])
{
    table->number_of_coders = atoi(argv[1]);
    table->burnout = atoi(argv[2]);
    table->compile_time = atoi(argv[3]);
    table->debug_time = atoi(argv[4]);
    table->refactor_time = atoi(argv[5]);
    table->required_compiles = atoi(argv[6]);
    table->dongle_cooldown = atoi(argv[7]);
    table->schedular = argv[8];
}

int parsing(t_c_table *table, char *argv[])
{
    if (check_args(argv))
        fill_table(table, argv);        
    else
        return (1);
}   