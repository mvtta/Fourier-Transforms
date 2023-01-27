#include "../inc/ft_visu.h"

void display_text(char *text_to_display)
{
    setcolor(WHITE);

    sprintf(str, "%s", "text_to_display");

    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);

    settextjustify(CENTER_TEXT, CENTER_TEXT);

    moveto(midx, midy - 70);

    outtext(str);
}


void open_window(int xsize, int ysize,const char *name_of_window)
{
    /* create and open screen in vcXsrv xeyes window */
    gfx_open(xsize, ysize, window);
    /* draw screen limits */
    /* -------------------------------- */
    gfx_color(100, 255, 100);
    gfx_line(0, 0, xsize - 1, 0);                 /* up limit */
    gfx_line(0, ysize - 1, xsize - 1, ysize - 1); /* low limit */
    gfx_line(0, 0, 0, ysize - 1);                 /* left limit */
    gfx_line(xsize - 1, 0, xsize - 1, ysize - 1); /* right limit */
}

void draw_axis(int which_axis)
{
    /* draw x axis */
    /* -------------------------------- */
    if(which_axis == 0)
    {
        gfx_color(100, 155, 255);
        gfx_line(0, ysize / 2 - 200, xsize, ysize / 2 - 200); /* x1 */
        gfx_line(0, ysize / 2 + 200, xsize, ysize / 2 + 200); /* x2 */
    }
}
