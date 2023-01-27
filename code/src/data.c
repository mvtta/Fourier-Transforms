#include "../inc/ft_visu.h"

void new_record(type_status **state)
{
    int i;
    (*state) = malloc(sizeof(state));
    if (!(*state))
        return;
    (*state)->signal[N_SAMPLES];
           return;
}

void free_state_date(type_status *record)
{
    if(record->signal)
        free(record->signal);
    if (record)
        free(record);
    record = NULL;
    return;
}
