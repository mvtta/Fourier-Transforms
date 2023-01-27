#include "../inc/ft_visu.h"

void new_signal(type_signal **signal)
{
    *signal = malloc(sizeof(type_signal));
    if (!*signal)
        return;
}

void *new_wave(type_wave **wave)
{

    *wave = malloc(sizeof(type_wave));
    if (!*wave)
        return;
}

type_wave *generate_wave(void)
{

    int a, x;

    a = 0;
    for (x = 0; x < N; x += 3)
    {
        /* calculate y value given x */
        int y = 50 * sin(a * 3.141 / 180);
        y = (YSIZE / 2 - 200) - y;
        /* saving datapoints for transform */
        gfx_point(x, y);
        a += 5;
    }
}

void generate_signal(type_status *input)
{
    int i;
    type_signal **signal = new_signal();
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

    for (i = 0; i < N; i++)
    {
        input->signal[i] = 0;
        input->signal[i] += amp1 * sinf(2 * M_PI * f1 * i / N);
        input->signal[i] += amp2 * sinf(2 * M_PI * f2 * i / N);
        input->signal[i] += amp3 * sinf(2 * M_PI * f3 * i / N);
        input->signal[i] /= 3;
    }
}

void display_signal(type_status *input)
{

    int i;
    int time_point = 0;

    int signal_color[3] = {100, 250, 130};
    int baseline_col[3] = {200, 100, 130};
    int signal_x = 150;
    int signal_y = 50;
    gfx_line(0, signal_y, N, signal_y);
    for (i = 0; i < N; i++)
    {
        time_point = input->signal[i];
        gfx_color(100, 250, 130);
        // gfx_point(N, signal_y * time_point);
    }

    /* draw cuts on signal */

}

/* M_PY for pi */