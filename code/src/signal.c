#include "../inc/ft_visu.h"

void new_wave(type_wave **wave)
{
    *wave = malloc(sizeof(type_wave));
    if (!*wave)
        return;
}

void generate_wave(type_wave **wave)
{
    int a, x, y;
    a = 0;
    for (x = 0; x < N_SAMPLES; x += 3)
    {
        y = (*wave)->amplitude * sin((*wave)->freq + a * 3.141 / 180); /* var radians is not so hard to do... */
        a += 5;
    }
}

void generate_signal(type_status **input)
{
    int i;

    /* this in a typedef pls */
    static int f1 = 4;
    static int f2 = 0;
    static int f3 = 0;

    static int amp1 = 1;
    static int amp2 = 1;
    static int amp3 = 1;

    /* normalize to 1 second range? later, values were ending in zero
    discretize time after implementation*/
    int signal[N_SAMPLES] = {0};
}

int *display_signal(type_status *s)
{

    static int f1 = 8;
    static int f2 = 7;
    static int f3 = 10;
    static int amp1 = 10;
    static int amp2 = 50;
    static int amp3 = 30;
    int     i, n, y, angle;
    float   pi = 3.141;
    int     signal[N_SAMPLES][N_SAMPLES] = {0};
    int     transform[N_SAMPLES] = {0};

    /* def screen placmeent + draw axis*/
    int signal_base_y = 150;
    int signal_height = 50;
    gfx_color(0, 250, 100);
    gfx_line(0, signal_base_y, N_SAMPLES, signal_base_y);

    /* generate 3 sines and add them to mix the frequencies 
       plus draw signal and save points in an array
       a small function like void generate_wave(type_wave **wave);
       would be cleaner
    */
    for (i = 0; i < N_SAMPLES; i++)
    {
        y = 0;
        y += amp3 * sin(f1 + angle * pi / 180);
        y += amp2 * sin(f2 + angle * pi / 180);
        y += amp3 * sin(f3 + angle * pi / 180);
        y = (300 / 2 - y);
        gfx_point(i, y);
        s->signal[i] = y;
        angle += 5;
    }

/* cut freq */
/* draw cuts on signal */
/* test using cuts */
/* save cut/test data at s->fourier_transform[n] */
/* draw transform */
/* allow mouse click scroll interactions */
}
