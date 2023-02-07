/* 
    header file for: ft_visu.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <complex.h>
#include <graphics.h>
#include <math.h>
#include "../lib/minilibx/mlx.h"
#include "../lib/libgfx/gfx.h"

#define N_SAMPLES 2364
#define XSIZE 2364
#define YSIZE 1768
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

typedef struct sample_buffer{

    float signal[N_SAMPLES]; /* signal data record of N samples */
    float real_[N_SAMPLES]; /* signal data record of N samples */
    float imaginary_[N_SAMPLES]; /* signal data record of N samples */
    float transformed[N_SAMPLES]; /* fourier transfrorm data points record */
} type_sample;


/* Prototypes Functions */
void new_record(type_sample **sample);

void new_wave(type_wave **wave);
void new_signal(type_signal **signal);

void generate_wave(type_wave **wave);
void generate_signal(type_sample **signal);

int *display_signal(type_sample *s);


/* vector operations
----------------------------------
 -> matrix mult
 -> analysis  
*/

void dft_(int *x, int *y);

/* display control
'''''''''''''''''''''''''''''''''''

 */
