#include "../inc/ft_visu.h"

type_status *new_record(void)
{
    int i;
    type_status *state;
    state = NULL;
    state = malloc(sizeof(state));
    if (!state)
        return (NULL);
    malloc(sizeof(state->signal[N]));
    if(!state->signal)
        return (NULL);
    return (state);
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
