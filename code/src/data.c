#include "../inc/ft_visu.h"

void new_record(type_sample **sample)
{
    int i;
    (*sample) = malloc(sizeof(sample));
    if (!(*sample))
        return;
    malloc(sizeof((*sample)->signal));
    malloc(sizeof((*sample)->real_ ));
    malloc(sizeof((*sample)->imaginary_ ));
    malloc(sizeof((*sample)->transformed));
           return;
}

void free_sample_date(type_sample *record)
{
    if(record->signal)
        free(record->signal);
    if (record)
        free(record);
    record = NULL;
    return;
}
