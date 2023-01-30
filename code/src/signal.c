#include "../inc/ft_visu.h"
#include <//usr/include/complex.h>

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

void generate_signal(type_status **input)
{
    int i;

    /* this in a typedef pls */
    static int f1 = 3;
    static int f2 = 112;
    static int f3 = 28;

    static int amp1 = 46;
    static int amp2 = 135;
    static int amp3 = 1;

    /* normalize to 1 second range? later, values were ending in zero
    discretize time after implementation*/
    int signal[N_SAMPLES] = {0};
}

int *display_signal(type_status *s)
{
    /*
        double pi = 3.1415926535897932384626433832795; */
    double pi = 3.1415;
    static int f1 = 8;
    static int f2 = 100;
    static int f3 = 10;
    static int amp1 = 4;
    static int amp2 = 50;
    static int amp3 = 30;

    int i, n, y, k, angle;
    /*    float pi = 3.141; */
    int signal[N_SAMPLES][N_SAMPLES] = {0};
    int transform[N_SAMPLES] = {0};

    /* def screen placmeent + draw axis*/
    int signal_base_y = 150;
    int signal_height = 50;
    int signal_lowbase_y = 550;
    int signal_lowheight = 400;
       gfx_color(50, 50, 250);
    /* mark time-domain axis */
    gfx_line(0, signal_base_y, N_SAMPLES, signal_base_y);
    /* mark half screen axis*/
    
    gfx_color(0, 250, 100);
    
    gfx_line(0, YSIZE / 2, N_SAMPLES, YSIZE/2);
    gfx_color(50, 50, 250);
    /* mark frequency-domain axis*/
    gfx_line(0, YSIZE -150, N_SAMPLES, YSIZE-150);

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
     λ lambda
     Φ phi
     Ω pmega
     δ delta
     φ phi (2?) - phase
     π pi


    y(t)= A * sin(2 * π * f * t + φ)

    Amplitude (A)— we can use it as a volume
    Frequency (f)— how many cycles per second it does
    Phase (phi)— starting point of sine wave
    Time (t)— just a time counter value (in our case)

     ------------------------------------------------------------------- */

    float m_amplitude;
    float m_frequency;
    float m_phase;
    float m_time;
    float m_deltaTime;
    float s_sample_rate;

    int sine1, sine2, sine3;

    // initialize values
    m_amplitude = 0.5;
    m_frequency = 500;
    m_phase = 0.01;
    m_time = 0.0;
    s_sample_rate = 44100;
    m_deltaTime = 1 / s_sample_rate;
    int fft;


    float a;
    for (i = 0; i < N_SAMPLES - 1; i += 1)
    {
        sine1 = amp1 * sin(f1 * a * (3.141 / 180) * m_time + m_phase); /* var radians is not so hard to do... */
        sine2 = amp2 * sin(f2 * a * (3.141 / 180) * m_time + m_phase); /* var radians is not so hard to do... */
        sine3 = amp3 * sin(f3 * a * (3.141 / 180) * m_time + m_phase); /* var radians is not so hard to do... */
        a += 0.1;
        m_phase += 0.1;
        gfx_color(240, 100, 140);
        gfx_point(i, 150 - sine1);
        gfx_color(70, 200, 100);
        gfx_point(i, 150 - sine2);
        gfx_color(100, 100, 250);
        gfx_point(i, 150 - sine3);
        y = sine1 + sine2 + sine3;
        s->signal[i] = y / 3;
        gfx_color(250, 250, 250);
        gfx_point(i, 150 - y);
    }
    complex j;

    int inv_samples = N_SAMPLES;
    for (n = 0; n < N_SAMPLES - 1; n++)
    {       
        for (k = 0; k < N_SAMPLES - 1; k++)
        {
             s->fourier_transformed[n] += s->signal[k] * exp(-j*2*pi*n*k / N_SAMPLES) / inv_samples--;
             /* printf("sample:%d  |   transform:%d\n", s->signal[n], s->fourier_transformed[n]); */ 
        }
        //printf("sample:%d  |   transform:%d\n", s->signal[n], s->fourier_transformed[n]);
        gfx_color(250, 250, 250);
        gfx_line(n, YSIZE - 150, n , YSIZE - 50);
    }


/* Euler identity:
 {\displaystyle e^{ix}=\cos x+i\sin x}
https://en.wikipedia.org/wiki/Euler%27s_identity#:~:text=Euler%27s%20identity%20is%20often%20cited%20as%20an%20example,additive%20identity.%20The%20number%201%2C%20the%20multiplicative%20identity.
 */
/* to compute ft (pen and paper) two ways:
        -> work with complex notation : get 1 complex coeficient
        e^(-j*2*pi*F*t) * dt
        -------------------------------
        -> work with real nonation: two real coeficients per frequency
        Xa(F) =  ∫ x(t)cos(2*pi*F*t * dt) and
        Xb(F) =  ∫ x(t)sin(2*pi*F*t * dt)       
        ------------------------------
        in engineering working with complex 
        running to minus inf to inf, but we're analysing a discrete time = 0 till sample.
        discrtee ft:

            N-1
        Xk = ∑ xn * e ^ -j*2pi*k*n/N
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
        -j | 2 * pi * k * n / N  | == -j ᵇn (easier for expansion ᵇn )       
            ---------------------         
        euler formula identity:

        const complex number -> Xₖ = Aₖ + Bₖ * J


          im(j)
         _  |
     Bₖ {   |   / (Aₖ, Bₖ)       
        {_  | /
            |/
        ----|---------> Real
            |{__} Aₖ

        Information we can extract:    
        
        Magnitude of (Aₖ, Bₖ):
                            _________
           (Aₖ, Bₖ) mag =  √ A²ₖ + B²ₖ

        Phase:        
            ∅ = arctan(Bₖ/Aₖ)                 
        
        Simplest case: Sine wave : 1Hz, Amplitude = 1
        Sampling Frequency: 8Hz
        Number Samples (N) : 8

                             X1 = x0 * -j * 2 *              ___________
                             pi(1)(0)/8+...till xn)        √ A²ₖ + B²ₖ
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
            Xₖ -> convention: frequency bin is the sum from all x(9)
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
U+220x	∀	∁	∂	∃	∄	∅	∆	∇	∈	∉	∊	∋	∌	∍	∎	∏
U+221x	∐	∑	−	∓	∔	∕	∖	∗	∘	∙	√	∛	∜	∝	∞	∟
U+222x	∠	∡	∢	∣	∤	∥	∦	∧	∨	∩	∪	∫	∬	∭	∮	∯
U+223x	∰	∱	∲	∳	∴	∵	∶	∷	∸	∹	∺	∻	∼	∽	∾	∿
U+224x	≀	≁	≂	≃	≄	≅	≆	≇	≈	≉	≊	≋	≌	≍	≎	≏
U+225x	≐	≑	≒	≓	≔	≕	≖	≗	≘	≙	≚	≛	≜	≝	≞	≟
U+226x	≠	≡	≢	≣	≤	≥	≦	≧	≨	≩	≪	≫	≬	≭	≮	≯
U+227x	≰	≱	≲	≳	≴	≵	≶	≷	≸	≹	≺	≻	≼	≽	≾	≿
U+228x	⊀	⊁	⊂	⊃	⊄	⊅	⊆	⊇	⊈	⊉	⊊	⊋	⊌	⊍	⊎	⊏
U+229x	⊐	⊑	⊒	⊓	⊔	⊕	⊖	⊗	⊘	⊙	⊚	⊛	⊜	⊝	⊞	⊟
U+22Ax	⊠	⊡	⊢	⊣	⊤	⊥	⊦	⊧	⊨	⊩	⊪	⊫	⊬	⊭	⊮	⊯
U+22Bx	⊰	⊱	⊲	⊳	⊴	⊵	⊶	⊷	⊸	⊹	⊺	⊻	⊼	⊽	⊾	⊿
U+22Cx	⋀	⋁	⋂	⋃	⋄	⋅	⋆	⋇	⋈	⋉	⋊	⋋	⋌	⋍	⋎	⋏
U+22Dx	⋐	⋑	⋒	⋓	⋔	⋕	⋖	⋗	⋘	⋙	⋚	⋛	⋜	⋝	⋞	⋟
U+22Ex	⋠	⋡	⋢	⋣	⋤	⋥	⋦	⋧	⋨	⋩	⋪	⋫	⋬	⋭	⋮	⋯
U+22Fx	⋰	⋱	⋲	⋳	⋴	⋵	⋶	⋷	⋸	⋹	⋺	⋻	⋼	⋽	⋾	⋿ */