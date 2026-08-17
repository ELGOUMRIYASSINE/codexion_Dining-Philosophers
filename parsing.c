#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// int gen_failed_responce(int index)
// {

// }
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