#include "header.h"

void print_log(t_coder* coder, t_c_table *data, char *state)
{
    if (coder->compiles_count == data->required_compiles)
        return;
    pthread_mutex_lock(&data->log_mutex);
    if (!get_end_simulation(data))
        printf("%lu %d, %s       l_dongle: %d r_dongle: %d, \n", get_time(MILIS) - data->start_time, coder->id, state, coder->left_dongle.dongle_id, coder->right_dongle.dongle_id);
    pthread_mutex_unlock(&data->log_mutex);
}