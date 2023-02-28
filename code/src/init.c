#include "../inc/ft_visu.h"
#include "../lib/minilibx/mlx.h"
//#include "/mnt/c/Users/valdetar/Downloads/dl_11_gc/dislin.h"


int	key_kill(int keycode, type_image *img, type_signal *s)
{
    /* attention":
                run "portability" error!
                on minirt my kecodes are set for macos
                here keycodes are for windows
                fix: run "portability" conditioning */
    printf("keycode:%d\n", keycode);
	if (keycode == 1216 || keycode == 27 || keycode == 32)
	{
		printf("user killed program\n");
		mlx_destroy_window(img->mlx, img->win);
		free(img->addr);
		free(img->img);
		(img->addr) = NULL;
		(img->img) = NULL;
		free(img);
        img = NULL;
		free(s);
        s = NULL;
		printf("program ended successfully");
		exit(0);
	}
	return(0);
}

/* void init_wave(type_signal *s)
{
    ()
} */

void	my_mlx_pixel_put(type_image *img, int x, int y, unsigned int color)
{
	size_t	offset;

	offset = ((y * img->line_length + x * img->bits_per_pixel / 8) / 4);
	img->addr[offset] = color;
}


int main(void)
{
    type_image  *image_data;
    type_signal *s;

    
    s = NULL;
    image_data = NULL;

    s = malloc(sizeof(type_sample));
    image_data = malloc(sizeof(type_image));
    image_data->mlx = mlx_init();
    image_data->win = mlx_new_window(image_data->mlx, 1024, 769, "Discrete Fourier Transform");
    image_data->img = mlx_new_image(image_data->mlx, 1024,769);
    image_data->addr = mlx_get_data_addr(image_data->img, &image_data->bits_per_pixel, &image_data->line_length, &image_data->endian);
    image_data->screen_x = 1024;
    image_data->screen_y = 769;
    mlx_hook(image_data->win, 2, 32, key_kill, image_data);
    mlx_hook(image_data->win, 2, 53, key_kill, image_data);
	mlx_hook(image_data->win, 17, 1216, key_kill, image_data);
    /* FUN BUG: 
    IMPLEMENTATION IS ASSUMING FREQ IS AMP
    AND AMP IS FREQ
    CHANGING AMP RETURNS DFT OF FREQ==AMP
    ON SAMPLE SIGNAL AND DRAW WAVE PARAMETERS ARE FIRTS TAKEN CORRECTLY,
    AND DISPLAYED AS SUCH
    */
    s->wave.freq = 100;
    s->wave.amplitude = 20;
    s->wave.angle = 0;
    while (1)
    {
        display_signal(s, image_data);
        //mlx_put_image_to_window(image_data->mlx, image_data->win, \
        image_data->img, 0, 0);
        mlx_loop(image_data->mlx);
    }
}


/* :::end of program
:::references:
-> https://www.youtube.com/watch?v=JQFJd3vfMbY
-> https://www.techcrashcourse.com/2015/08/c-program-draw-sine-graph-wave-graphics.html
 */
