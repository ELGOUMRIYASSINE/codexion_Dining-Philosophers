#include <sys/time.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>


int main()
{
    int test[2];

    
    test[0] = 0;

    if (test[0])
    {
        printf("empty for now\n");
        printf("%d", test[0]);
        test[0] = 1;
        printf("filled\n");
        printf("%d", test[0]);
    }
}
