
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <graphics.h>


 /* right lib linker ok 
 gcc test1.c -LLIBDIR /usr/local/lib/libgraph.so.1.0.2 */

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
 
    circle(50, 50, 30);
    MPutString ("hello");
 
    delay(500000);
    closegraph();
    return 0;
}