#include "../inc/ft_visu.h"
#include <complex.h>
#include <time.h>


void new_wave(type_wave **wave)
{
    *wave = malloc(sizeof(type_wave));
    if (!*wave)
        return;
}

void generate_wave(type_wave **wave)
{
    int a, x, y;
    a = 0;
    for (x = 0; x < N_SAMPLES; x += 3)
    {
        y = (*wave)->amplitude * sin((*wave)->freq + a * 3.141 / 180); /* var radians is not so hard to do... */
        a += 5;
    }
}

void generate_signal(type_sample **input)
{
    int i;

    /* this in a typedef pls */
    static double f1 = 3;
    static double f2 = 112;
    static double f3 = 28;

    static double amp1 = 46;
    static double amp2 = 135;
    static double amp3 = 1;

    /* normalize to 1 second range? later, values were ending in zero
    discretize time after implementation*/
}


void create_axis(type_signal *s, type_image *img)
{
    s->wave.angle = 0;
    s->wave.iter = 0;
    for (int i = 0; i < N_SAMPLES - 1; i += 1)
    {
        s->wave.iter = s->wave.amplitude * \
        sin(s->wave.freq + s->wave.angle * (M_PI / 180));
        s->wave.angle += 5;
        s->sample.signal[i] = s->wave.iter;
    }
    return;
}


void discrete_to_screen(type_image *img, int old_x, int old_y, int i)
{
    int width_new = img->screen_x;
    int height_new = img->screen_y;
    img->scaled_x = (old_x * width_new)/M_PI;
    img->scaled_y = (old_y * height_new)/20;
    return;
}

void sample_signal(type_signal *s, type_image *img)
{
    s->wave.angle = 0;
    s->wave.iter = 0;
    srand(time(0));
    for (int i = 0; i < N_SAMPLES - 1; i += 1)
    {
        s->wave.iter = s->wave.amplitude * \
        sinf(s->wave.freq + s->wave.angle * (M_PI / 180));
        s->wave.angle += 5;
        s->sample.signal[i] = s->wave.iter;

        mlx_pixel_put(img->mlx,img->win, i, (img->screen_y - 300) - s->wave.iter, BLUE);
    }
    return;
/*     srand(time(0));
    for (double n=0 ; n < img->screen_x - 1 ; n += 1)
    {
        for (int i = 0; i< N_SAMPLES -1; i++)
        {

        s->sample.signal[i] = s->wave.amplitude * \
        sin(s->wave.freq + s->wave.angle * (M_PI / 180));
        s->wave.angle += 5;
        mlx_pixel_put(img->mlx,img->win, , img->screen_y - (300) - s->sample.signal[i], RED);

        }
    }  */
}


void draw_segments(type_image *img, int origin, int direction, int color)
{
    for(int i = 0; i <= direction; i++)
    {
       // mlx_pixel_put(img->mlx, img->win, origin, i, color);
    }
    return;
}

void create_panes()
{
    return;
}

void draw_wave()
{
    return;
}

static void mark_axis_freq(type_image *img)
{
    char *values;
    values = "| ";
    char buffer [sizeof(int)*8+1];
     
    for(int i = 0; i <=XSIZE-1; i++)
    {         
                if (i%100==0)
                {
                    sprintf(buffer, "%d", i);
                    mlx_string_put(img->mlx, img->win, i, img->screen_y - 80, YELLOW, buffer);
                }
                    
    }
    return;
}

void display_dft(type_signal *s, type_image *img)
{
    for(int i = 0; i < img->screen_x - 1; i++)
    {
        mark_axis_freq(img);
        mlx_pixel_put(img->mlx, img->win, i, img->screen_y - 100 - CLAMP_MAX(s->sample.transformed[i]/1100), RED);
    }
    return;
}

int *display_signal(type_signal *s, type_image *img)
{

    /* iterators */
    int i, n, k, angle;
 
    int     frequency = 500;
    int     amplitude = 40;
    int     sine1 = 0;
    int     sr = 10000;
    float   fs = 44100;
    float   a, b;
    float   t;
    float   y;
    double  omega;
    complex j;
    complex double x[N_SAMPLES];   // complex-valued discrete-time signal
    complex double X[N_SAMPLES];   // complex-valued frequency-domain samples
    s->sample.real_[N_SAMPLES] = 0;
    s->sample.imaginary_[N_SAMPLES] =0 ;
    s->sample.transformed[N_SAMPLES] = 0;
    s->sample.screen_time[N_SAMPLES] = 0;
    int to_sin = 3*N_SAMPLES/4;
    j = I;
    omega = (2 * M_PI / n) / sr;
  
    mlx_string_put(img->mlx, img->win,XSIZE/2 - 1,20, GREY, "DFT");
    mlx_string_put(img->mlx, img->win, 20, img->screen_y - 250, RED, "time domain");

    for (i = 0; i < img->screen_x - 1; i += 1)
    { 
        mlx_pixel_put(img->mlx,img->win, i, img->screen_y - 100, BLUE);
        mlx_pixel_put(img->mlx,img->win, i, img->screen_y - 300, BLUE);
    }
    mlx_string_put(img->mlx, img->win, 20, img->screen_y - 50, RED, "frequency domain");
    sample_signal(s, img);
    s->sample.transformed[N_SAMPLES] = 0;
    s->sample.real_[N_SAMPLES] = 0;
    float transformed[N_SAMPLES];
   
    for (k = 0; k < N_SAMPLES -1; k += 1)
    {
        s->sample.real_[k] = 0;
        for (n = 0; n < N_SAMPLES - 1; n += 1)
        {
            s->sample.real_[k] += s->sample.signal[n] * cosf(n * k * 2 * M_PI / N_SAMPLES);
            s->sample.imaginary_[k] = 0;
            for(n = 0; n< N_SAMPLES - 1; n++)
                s->sample.imaginary_[k] -= s->sample.signal[n] * sinf(n * k * 2 * M_PI / N_SAMPLES);
        }
            s->sample.transformed[k] = (s->sample.real_[k] * s->sample.real_[k]) + ( s->sample.imaginary_[k] * s->sample.imaginary_[k]);
           // s->sample.transformed[n] = (s->sample.real_[n] * s->sample.real_[n]) + ( s->sample.imaginary_[n] * s->sample.imaginary_[n]);
            printf("i: %d - transf: %f - /1100 : %f\n",  k, s->sample.transformed[k],s->sample.transformed[k]/1100);
    }
   display_dft(s,img);
}
  












































/* *************************************************************************************** */
    /* ------ENDLESS NOTES TO SORT --------
        todo: define x axis of time frequency rate / dimension / position
        +
        generate signal mode freq's
        test if indeed results are good
        tada!
    ----------------- */

    /* Euler identity:
     {\displaystyle e^{ix}=\cos x+i\sin x}
    https://en.wikipedia.org/wiki/Euler%27s_identity#:~:text=Euler%27s%20identity%20is%20often%20cited%20as%20an%20example,additive%20identity.%20The%20number%201%2C%20the%20multiplicative%20identity.
     */
    /* to compute ft (pen and paper) two ways:
            -> work with complex notation : get 1 complex coeficient
            e^(-j*2*pi*F*t) * dt
            -------------------------------
            -> work with real nonation: two real coeficients per frequency
            Xa(F) =  ??? x(t)cos(2*pi*F*t * dt) and
            Xb(F) =  ??? x(t)sin(2*pi*F*t * dt)
            ------------------------------
            in engineering working with complex
            running to minus inf to inf, but we're analysing a discrete time = 0 till sample.
            discrtee ft:

                N-1
            Xk = ??? xn * e ^ -j*2pi*k*n/N
                n=0

            freq of sample = sum of
            k - > sample (y value at time of sample)
            j -> imaginary part
            N -> number of samples
            n -> t (time)
            F -> freq

            k / N -> Freq && n -> t (time)

            ?

            expanding the sumation for the discrete Fourier transform:
                ---------------------
            -j | 2 * pi * k * n / N  | == -j ???n (easier for expansion ???n )
                ---------------------
            euler formula identity:

            const complex number -> X??? = A??? + B??? * J


              im(j)
             _  |
         B??? {   |   / (A???, B???)
            {_  | /
                |/
            ----|---------> Real
                |{__} A???

            Information we can extract:

            Magnitude of (A???, B???):
                                _________
               (A???, B???) mag =  ??? A????? + B?????

            Phase:
                ??? = arctan(B???/A???)

            Simplest case: Sine wave : 1Hz, Amplitude = 1
            Sampling Frequency: 8Hz
            Number Samples (N) : 8

                                 X1 = x0 * -j * 2 *              ___________
                                 pi(1)(0)/8+...till xn)        ??? A????? + B?????
          _______________________________________________________________

            sample values:               sum:                     mag:(Hz)
          _______________________________________________________________
            x0 = 0                       0
            x1 = 0.707                   0,-4j                     4
            x2 = 1                       0
            x3 = 0.707                   0
            x4 = 0                       0
            x5 = -0.707                  0
            x6 = -1                      0
            x7 = 0.07                    0,+4j                     4
          ________________________________________________________________
          Note:
                X??? -> convention: frequency bin is the sum from all x(9)
                sum + expanded in case of doubt:

                -> 0 == x0                   -> 0.07 == x1
                X1 = 0 * -j*2*pi(1)(0)/8 + 0.07 * e ^ -j* 2 * pi(1)(1)/8
          ________________________________________________________________

            Bellow nyquist (?) x1 and x7 spike, in this case only one freq (sine 1 Hz)
            trick: sum both, 4 + 4 = 8 /8 == 1

    */

    // gfx_line(0, signal_base_y, N_SAMPLES, signal_base_y);

    /*
      for (i = 0; i < N_SAMPLES; i++)
        {
            sine1 = m_amplitude * sin(2 * pi * m_frequency * m_time + m_phase);
    sine2 = amp2 * sin(2 * pi * f2 * m_time + m_phase);
            sine3 = amp3 * sin(2 * pi * f3 * m_time + m_phase);
            gfx_color(255, 50, 100);
            s->signal[i] = sine1;
            gfx_point(m_time + signal_base_y, sine1 + signal_height);
    gfx_point(m_time + signal_base_y, sine2 + signal_height);
            gfx_point(m_time + signal_base_y, sine3 + signal_height);
            m_time += m_deltaTime;
        } */

    /* cut freq */
    /* draw cuts on signal */
    /* test using cuts */
    /* fft calculate twiddle factor:


    -> above x axis $$exp^(-2pi*i*k)/N == expo(-2*pi*K/2*a)

            -> n * a is always equal to N/2
            -> W[(k * a) % (n * a)] is the negation of twiidle

    "The twiddle factors are equally spaced points on the unit circle,
    and there is an even number of points because N is a power-of-two.
    After going around half of the circle (starting at 1,
    going counter clockwise above the X-axis),
    the second half is a repeat of the first half but this
     time it's below the X-axis (the points can be reflected through the origin).
    That is why Temp is subtracted the second time.
    That subtraction is the negation of the twiddle factor."
    */
    /* save cut/test data at s->fourier_transform[n] */
    /* draw transform */
    /* allow mouse click scroll interactions */
}

/*
U+220x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+221x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+222x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+223x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+224x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+225x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+226x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+227x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+228x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+229x	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+22Ax	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+22Bx	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+22Cx	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+22Dx	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+22Ex	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???
U+22Fx	???	???	???	???	???	???	???	???	???	???	???	???	???	???	???	??? */

/* Notes on
generation waves/signals and the use of phi and twiddle
ref->
 ------------------------------------------------------------------- */

/* generate 3 sines and add them to compose signal
   plus draw signal and save points in an array
   a small function like void generate_wave(type_wave **wave);
   would be cleaner
*/
/*
   float angle = pi*((float) group+1)/step_d;
   twiddle_re = cos(angle);
   twiddle_im = sin(angle);
 } */

/* ------------------------------------------------------------------- */
/*
simple sine wave formula:
 ?? lambda
 ?? phi
 ?? pmega
 ?? delta
 ?? phi (2?) - phase
 ?? pi

y(t)= A * sin(2 * ?? * f * t + ??)

Amplitude (A)??? we can use it as a volume
Frequency (f)??? how many cycles per second it does
Phase (phi)??? starting point of sine wave
Time (t)??? just a time counter value (in our case)

 ------------------------------------------------------------------- */

/* -----------------------------------------
I'm still doing absolute nonsense with the values,
have to choose either a range of pi mult or 0/1 or real adjusted to screen
(bad idea yet current one)
plus clean this code pls
----------------------------------------- */
