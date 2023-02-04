#include "../inc/ft_visu.h"
#include "../lib/minilibx/mlx.h"

/* please finish makefile gcc like this is not ok
gcc -g src/init.c src/signal.c src/data.c  lib/libgfx/gfx.c inc/ft_visu.h lib/libgfx/gfx.h -I -lmlx -lm -lXext -lX11 -o ./dft */

int main(int ac, char **av)
{
    int c, n;
    type_sample *s;

    gfx_open(XSIZE, YSIZE, "fft - hello window");       /* create open screen xeyes xserver */

    s = NULL;
    s = malloc(sizeof(type_sample));                        /* alloc and bzero,fix later  */
    for (n = 0; n < N_SAMPLES; n++)
        s->transformed[n] = 0;

    /* -----------------------------------
    keep window open waiting for cmds*/
    while (1)
    {
        display_signal(s);
        c = gfx_wait();
        if (c == 'q') /* QUIT */
            break;
    }
    return (0);
}

/* :::end of program
:::references:
-> https://www.youtube.com/watch?v=JQFJd3vfMbY
-> https://www.techcrashcourse.com/2015/08/c-program-draw-sine-graph-wave-graphics.html
 */
