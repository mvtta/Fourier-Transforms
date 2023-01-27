#include "../inc/ft_visu.h"

void new_wave(type_wave **wave)
{

    *wave = malloc(sizeof(type_wave));
    if (!*wave)
        return;
}

void generate_wave(type_wave **wave)
{

    int a, x;

    a = 0;
    for (x = 0; x < N_SAMPLES; x += 3)
    {
        /* calculate y value given x */
        int y = 50 * sin(a * 3.141 / 180);
        y = (YSIZE / 2 - 200) - y;
        /* saving datapoints for transform */
        gfx_point(x, y);
        a += 5;
    }
}

void generate_signal(type_status **input)
{
    int i;
    static int f1 = 4;
    static int f2 = 0;
    static int f3 = 0;

    static int amp1 = 1;
    static int amp2 = 1;
    static int amp3 = 1;

    /*     type_wave *wave1 = generate_wave();
        type_wave *wave2 = generate_wave();
        type_wave *wave3 = generate_wave();

     */
    /* normalize to 1 second range */
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
    float   pi = 3.14;
    double  angle = 0.0;
    int     i, n, y;
    int     time_point = 0;
    int     signal_color[3] = {100, 250, 130};
    int     baseline_col[3] = {200, 100, 130};
    int     signal_x = 150;
    int     signal_y = 50;
    int     signal[N_SAMPLES][N_SAMPLES] = {0};
    int     transform[N_SAMPLES] = {0};

    /* def screen placmeent + draw axis*/
    int signal_base_y = 150;
    int signal_height = 50;
    gfx_color(0, 250, 100);
    gfx_line(0, signal_base_y, N_SAMPLES, signal_base_y);

    /* generate 3 sines and add them to mix the frequencies 
       plus draw signal and save points in an array*/
    for (i = 0; i < N_SAMPLES; i++)
    {
        y = 0;
        y += amp3 * sin(f1 + angle* 3.141 / 180);
        y += amp2 * sin(f2 + angle * 3.141 / 180);
        y += amp3 * sin(f3 + angle* 3.141 / 180);
        y = (300 / 2 - y);
        gfx_point(i, y);
        s->signal[i] = y;
        angle += 5;
    }

/* cut freq */
    gfx_color(100, 100, 200);
    for (i = 0; i < n; i++)
    {
        time_point = transform[i];
        gfx_color(100, 250, 130);
        gfx_point(signal_y * transform[i], time_point);
    }

    /* draw cuts on signal */
}

/* M_PY for pi */