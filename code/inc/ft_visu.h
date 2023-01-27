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

#define XSIZE 1920
#define YSIZE 1080
#define N 1000
#define A 40

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

void new_wave(type_wave **wave);
void new_signal(type_signal **signal);

void generate_wave(type_wave **wave);
void generate_signal(type_status **signal);

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
