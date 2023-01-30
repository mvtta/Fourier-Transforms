#include "../inc/ft_visu.h"
#include "../lib/libgfx/gfx.h"

/*
   No so discrete Fourier Transform
*/
int dft( int dir, int m, int *x1, int *y1 ) {

    long i, k;
    int arg;
    int cosarg, sinarg;
    int *x2 = NULL;
    int *y2 = NULL;

    x2 = malloc( m * sizeof( int ) );
    y2 = malloc( m * sizeof( int ) );
    if ( x2 == NULL || y2 == NULL )
        return( FALSE );

    for ( i = 0; i < m; i++ ) {
        x2[i] = 0;
        y2[i] = 0;
        arg = - dir * 2.0 * 3.141592654 * ( int ) i / ( int ) m;
        for ( k = 0; k < m; k++ ) {
            cosarg = cosl( k * arg );
            sinarg = sinl( k * arg );
            x2[i] += ( x1[k] * cosarg - y1[k] * sinarg );
            y2[i] += ( x1[k] * sinarg + y1[k] * cosarg );
        }
    }

    /* Copy the data back */
    if ( dir == 1 ) {
        for ( i = 0; i < m; i++ ) {
            x1[i] = x2[i] / ( int ) m;
            y1[i] = y2[i] / ( int ) m;
        }
    } else {
        for ( i=0; i<m; i++ ) {
            x1[i] = x2[i];
            y1[i] = y2[i];
        }
    }

    free( x2 );
    free( y2 );
    return( TRUE );
}

/* int main( int argc, char **argv ) {

    int xaxis[6] = { 0, 1, 2, 3, 4, 5 };
    int yaxis[6] = { 4, 4, 4, 4, 4, 4 };

    printf( "xaxis values: %d, %d, %d, %d, %d, %d\n",xaxis[0],xaxis[1],xaxis[2],xaxis[3],xaxis[4],xaxis[5] );
    printf( "yaxis values: %d, %d, %d, %d, %d, %d\n",yaxis[0],yaxis[1],yaxis[2],yaxis[3],yaxis[4],yaxis[5] );

    dft( 1, 6, xaxis, yaxis );

    printf( "new xaxis values: %d, %d, %d, %d, %d, %d\n",xaxis[0],xaxis[1],xaxis[2],xaxis[3],xaxis[4],xaxis[5] );
    printf( "new yaxis values: %d, %d, %d, %d, %d, %d\n",yaxis[0],yaxis[1],yaxis[2],yaxis[3],yaxis[4],yaxis[5] );

    return 0;

} */