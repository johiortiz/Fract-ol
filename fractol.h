/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:53:01 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 20:59:27 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_range
{
	double			min;
	double			max;
}					t_range;

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct s_fractal
{
	bool			mouse_down;
	double			mouse_down_x;
	double			mouse_down_y;
	double			drag_start_offset_x;
	double			drag_start_offset_y;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*base_img;
	char			*type;
	double			zoom;
	double			base_zoom;
	double			offset_x;
	double			offset_y;
	int				max_iter;
	t_complex		julia_c;
	int				color_shift;
	double			mouse_x;
	double			mouse_y;
	int				iterations_definition;
	bool			need_render;
	bool			is_zooming;
	int				current_y;
	unsigned int	frame_count;
	bool			scrolling_this_frame;
}					t_fractal;

/* strings_utils.c */
int					ft_strncmp(char *s1, char *s2, int n);
void				ft_putstr_fd(char *s, int fd);
double				ft_atodbl(char *s);

/* init.c */
void				fractal_init(t_fractal *f, int ac, char **av);

/* render.c */
void				fractal_render(t_fractal *f);
void				fractal_render_line(t_fractal *f);
void				fractal_render_preview(t_fractal *f);
void				scaled_zoom_render(t_fractal *f, double zoom_factor);
void				update_base_image(t_fractal *f);

/* mandelbrot.c */
uint32_t			draw_mandelbrot(t_fractal *f, int x, int y);

/* julia.c */
uint32_t			draw_julia(t_fractal *f, int x, int y);

/* maths_utils.c */
double				map(double val, t_range in_range, t_range out_range);
t_complex			complex_add(t_complex a, t_complex b);
t_complex			complex_square(t_complex z);

/* color.c */
int					get_color(int iter, int max_iter, int shift);

/* hooks.c */
void				set_hooks(t_fractal *f);

/* hooks_utils.c */
void				scrollhook(double xdelta, double ydelta, void *param);
void				keyhook(mlx_key_data_t key, void *param);
void				mousehook(mouse_key_t button, action_t action,
						modifier_key_t mod, void *param);
void				cursorhook(double xpos, double ypox, void *param);
void				loop_hook(void *param);

/* cleanup.c */
void				cleanup_fractal(t_fractal *f);

#endif