#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef pthread_mutex_t t_mtx;
typedef struct coders_table t_c_table;
typedef struct coder    t_coder;
int parsing(t_c_table *table, char *argv[]);

typedef struct dongle {
    t_mtx  dongle;  
    int     dongle_id;
    int    schedular[2];
}           t_dongle;

struct coder {
    pthread_t thread;
    int id;
    long compiles_count;
    long last_compile; // time from the last compile
    t_dongle left_dongle;
    t_dongle right_dongle;
    t_c_table* table; 
};

struct coders_table {   
    long number_of_coders;
    long burnout;
    long compile_time;
    long debug_time;
    long refactor_time;
    long required_compiles;
    long dongle_cooldown;
    char* schedular;
    bool end;
    t_dongle* dongles;
    t_coder* coders;
};