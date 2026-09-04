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
int init_utils(t_c_table* table);

typedef struct dongle {
    pthread_mutex_t  dongle;  
    int     dongle_id;
    bool    available;
    long    last_usage;
    pthread_cond_t cond;
    int    schedular[2];
}           t_dongle;

typedef enum timer {
    SECOND,
    MILIS,
    MICROS
}      t_time;

struct coder {
    pthread_t coder;
    int id;
    long compiles_count;
    long last_compile; // time from the last compile
    t_mtx coder_mutex; // for monitor
    bool finished;
    t_dongle *first_dongle;
    t_dongle *second_dongle;
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
    bool all_coders_on;
    long start_time;
    char* schedular;
    bool end;
    t_mtx table_mutex;
    t_mtx log_mutex;
    t_dongle* dongles;
    t_coder* coders;
};

typedef struct leaker
{
    void *space;
    struct leaker *next_space;
} t_leak;

// getters and setters
bool get_end_simulation(t_c_table *table);
void set_long(t_mtx *mutex, long* dest, long value);
long get_long(t_mtx *mutex, long* value);
bool get_bool(t_mtx *mutex, bool* value);
void set_bool(t_mtx *mutex, bool *dest, bool value);
void wait_all_coders(t_c_table *table);
void cycle_on(t_c_table* table);
long get_time(t_time time_type);
void    t_usleep(unsigned long ms, t_c_table *data);
void print_log(t_coder *coder, t_c_table *data, char *state);
void compile(t_coder *coder, t_c_table *table);
void aquire_dongles(t_dongle *coder_dongle, t_c_table *table);
bool cold_elapsed(t_dongle *dongle, t_c_table *table);
void* monitor_simulation(void *table_data);

