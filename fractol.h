/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:53:01 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/24 18:15:46 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include <stdio.h>	
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include "MLX42/include/MLX42/MLX42.h"
//# include "libft/libft.h"

# define THREADS 8

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

# define KEY_ESCAPE MLX_KEY_ESCAPE
# define KEY_LEFT MLX_KEY_LEFT
# define KEY_RIGHT MLX_KEY_RIGHT
# define KEY_UP MLX_KEY_UP
# define KEY_DOWN MLX_KEY_DOWN

# define MOUSE_SCROLL_UP 1
# define MOUSE_SCROLL_DOWN -1

/*
 * COLORS
*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red


typedef struct	s_complex
{
	double	x;
	double	y;
}		t_complex;

typedef struct	s_fractal
{
	char	*name;
	mlx_t	*mlx;
	mlx_image_t	*img;
	double	escape_value;
	int		iterations_definition;
	double	mouse_x;
	double	mouse_y;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}						t_fractal;

typedef struct	s_threads_data
{
	t_fractal	*f;
	int		start_y;
	int		end_y;
} t_threads_data;

// Strings utils
int ft_strncmp(char *s1, char *s2, int n);
void    putstr_fd(char *s, int fd);
double  atodbl(char *s);

// Init
void	fractal_init(t_fractal *fractal);

// Render
void	fractal_render(t_fractal *fractal);

// Math
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//*** hooks_events ***
void			key_handler(mlx_key_data_t keydata, void *param);

//*** clean_up ***
void		close_handler(void *param);
void		mouse_handler(double xdelta, double ydelta, void *param);
void		julia_track(double xpos, double ypos, void *param);

#endif