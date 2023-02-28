/* 
    header file for: ft_visu.h

    structure:
                * includes
                * atomic data -> user defined data types
                * main data frames -> packing user defines data types
                * function prototypes:
                * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <complex.h>
#include <graphics.h>
#include <math.h>
#include "../lib/minilibx/mlx.h"
#include "../lib/libgfx/gfx.h"

#define N_SAMPLES 1100
#define N_SAMPLES_F (float)16
#define XSIZE 1024
#define YSIZE 769
#define A 40
#define RED 16711680
#define BLUE 255
#define GREEN 39680
#define GREY 13158600
#define YELLOW 13158479
#define CLAMP_MIN(n) (n>=0?n:0)
#define CLAMP_MAX(n) (n>=YSIZE?CLAMP_MIN(n):n)


/* image and window data frame for graphical operations */
typedef struct	s_data {
	int		endian;
	int		bits_per_pixel;
	int		line_length;
	char	*addr;
    void    *win;
	void	*img;
    void    *mlx;
    int     screen_x;
    int     screen_y;
    int     scaled_x;
    int     scaled_y;
} type_image;

/* wave propertie data */
typedef struct wave_data{
    int     id; /* wave id */
    int     iter; /* iter */
    int     freq;
    int     angle;
    double  real;
    double  wave_len;
    double  imaginary;
    double  angular_freq;
    double  amplitude;
} type_wave;

/* frequency samples before and after transformation */
typedef struct sample_buffer{
    float signal[N_SAMPLES]; /* signal data record of N samples */
    float real_[N_SAMPLES]; /* signal data record of N samples */
    float imaginary_[N_SAMPLES]; /* signal data record of N samples */
    float transformed[N_SAMPLES];
    float screen_time[N_SAMPLES]; /* fourier transfrorm data points record */
    float *screen_freq;
    float f[N_SAMPLES]; /* fourier transfrorm data points record */
} type_sample;

/* packing type_sample & type_wave properties */
typedef struct signal_data{
    type_wave   wave;
    type_sample sample;
} type_signal;

/* Prototypes Functions */


/* data structure utils */
void new_record(type_sample **sample);
void new_wave(type_wave **wave);
void new_signal(type_signal **signal);
/* memory managemt utils */
int	key_kill(int keycode, type_image *img, type_signal *s);


/* generators */
void generate_wave(type_wave **wave);
void generate_signal(type_sample **signal);


/* sampling */
void sample_signal(type_signal *s, type_image *img);

/* coordinates utils */
void discrete_to_screen(type_image *img, int old_x, int old_y, int i);



/* drawing */
void my_mlx_pixel_put(type_image *img, int x, int y, unsigned int color);
void draw_segments(type_image *img, int origin, int direction, int color);
void display_dft(type_signal *s, type_image *img);

/* dft computation */
int *display_signal(type_signal *s, type_image *img);



/* vector operations
----------------------------------
 -> matrix mult
 -> analysis  
*/

void dft_(int *x, int *y);

/* display control
'''''''''''''''''''''''''''''''''''

 */


