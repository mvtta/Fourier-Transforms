#include "../inc/ft_visu.h"
#include "../lib/minilibx/mlx.h"

/* gcc src / init.c lib / minilibx / libmlx_Linux.a - I - lmlx - lXext - lX11
curr compiling with */

int main(int ac, char **av)
{
    int angle = 40;
    int c,n;
    double x, y;


    /* initialize data frame create and open screen in 
    vcXsrv xeyes window draw bounding frame
    -------------------------------------------------*/
    gfx_open(N_SAMPLES, YSIZE, "FFT");
    
    type_status *s =  NULL;
    s = malloc(sizeof(type_status));

        for (n = 0; n < N_SAMPLES; n++)
    {
        s->fourier_transformed[n] = 0;
    }
    
    
    /* -------------------------------------- */

    while (1)
    {
        display_signal(s);
        /* q = = quit */
        c = gfx_wait();
        if (c == 'q')
            break;
    }
    return (0);
}

/* --------------------------------- */
/* end of program                    */
/* references:
-> https://www.youtube.com/watch?v=JQFJd3vfMbY
-> https://www.techcrashcourse.com/2015/08/c-program-draw-sine-graph-wave-graphics.html
->

 */

/*
------------------------------------
----------------------------------------=
super preety nonsense pixel art gen
-----------------------------------------
-----------------------------------
*/

/* while (1)
{
// Wait for the user to press a character.
c = gfx_wait();
if (c == 'q')
            break;
int a = 0;
x = 0;
for (x; x < xsize; x += 3)
{
            calculate y value given x
            y = 50 * sin(angle * 3.141 / 180);
            y = (ysize / 2 - 200) - y;
            saving datapoints for transform
            gfx_point(x, y);
            int x2, y2;
            long i, k;
            for (i = 0; i < c; i++)
            {
                x2 = 0;
                y2 = 0;
                for (k = 0; k < 50; k++)
                {
                    int arg = -angle * 2.0 * 3.141592654 * (int)i / (int)50;
                    int cosarg = cosl(k * arg);
                    int sinarg = sinl(k * arg);
                    x2 += x * cosarg - y + 400 * sinarg;
                    y2 += x * sinarg + y + 400 * cosarg;
                    gfx_line(y2, 0, y2, x2);
                }
            }
            angle += 5;
}
} */