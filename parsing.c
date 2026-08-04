#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int check_values(char *argument, int index)
{
    char    *fields[8];
    const char *fields[] = {
        "coders",   // number_of_coders: how many coder threads (and dongles) exist
        "burnout",  // time_to_burnout: max wait time (ms) before a coder burns out
        "compile",  // time_to_compile: duration (ms) of the compiling phase
        "debug",    // time_to_debug: duration (ms) of the debugging phase
        "refactor", // time_to_refactor: duration (ms) of the refactoring phase
        "required", // number_of_compiles_required: compiles needed per coder to succeed
        "cooldown", // dongle_cooldown: rest time (ms) before a released dongle can be reused
        "sched"     // scheduler: arbitration policy, must be "fifo" or "edf"
    };
}

int check_args(char *argv[])
{
    int     i;
    char    *arg;
    int     j;
    i = 1;
    while (i < 8)
    {
        j = 0;
        if (i == 7 && (!memcmp(argv[i], "fifo", 4) || !memcmp(argv[i], "edf", 3)))
            return (0);
        else 
        {
            while (argv[i][j])
            {
                if (!isdigit((char) argv[i][j]) && isprint((char) argv[i][j]))
                    return (0);
                j++;
            }
        }
        i++;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    if (argc != 9)
    {
        printf("wrong arguments count, 8 args needed");
        return 1;
    }
    if (check_args(argv))
        printf("valid values");
    else
        printf("invalid values");
}   