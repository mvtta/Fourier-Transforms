/* 
    header file for: ft_visu.h
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* #include <graphics.h> */
#include <string.h>
#include "../lib/minilibx/mlx.h"
#include "../lib/libgfx/gfx.h"

#define XSIZE 1000
#define YSIZE 800
#define N 1000

typedef struct wave{

    int id; /* wave id */
    int angle;
    int freq;
    double real;
    double wave_len;
    double imaginary;
    double angular_freq;
    double amplitude;
} type_wave;

typedef struct data{

    double t; /* for time */
    int k_freq; /* current frequency */
    int Xk; /* amout of freq in signal */
    int n; /* sample being considered */
    int x; /* valueof signal at time of sample being considered 
    -> n */
} type_signal;

typedef struct state_buffer{

    int signal[N]; /* signal data record of N samples */
    int fourier_transformed[N]; /* fourier transfrorm data points record */
} type_status;


/* Prototypes Functions */
type_signal *new_signal();


void *new_wave(type_wave **wave);
type_wave *generate_wave(void);
void new_signal(type_signal **signal);


void generate_signal(type_status *signal);
void display_signal(type_status **input);

/* vector operations
----------------------------------
 -> matrix mult
 -> analysis  
*/

void dft_(int *x, int *y);

/* display control
'''''''''''''''''''''''''''''''''''

 */
