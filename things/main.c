#include <sys/time.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>


long get_time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int main()
{

    long start = get_time_ms();

    while (1)
    {
        long now = get_time_ms();
        if (now - start >= 10)
        {
            printf("10ms have passed!\n");
            break;
        }    
    }
    return (0);
}

