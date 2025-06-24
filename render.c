/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:32:36 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/24 18:08:40 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, mlx_image_t *img, int color)
{
	if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
		mlx_put_pixel(img, x, y, color);
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static int	get_color(int i, int max_iter)
{
	if (i == max_iter)
		return (BLACK);
	
	double t = (double)i / max_iter;
	int	r = (int)(9 * (1 - t) * t * t * t * 255);
	int	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

// static void	handle_pixel(int x, int y, t_fractal *fractal)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	int					i;
// 	int					color;
	
// 	i = 0;
	
// 	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
// 	z.y = (map(y, -2, +2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

// 	mandel_vs_julia(&z, &c, fractal);
	
// 	while (i < fractal->iterations_definition)
// 	{
// 		z = sum_complex(square_complex(z), c);
// 		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
// 		{
// 			color = get_color(i, fractal->iterations_definition);
// 			my_pixel_put(x, y, fractal->img, color);
// 			return ;
// 		}
// 		++i;
// 	}
// 	my_pixel_put(x, y, fractal->img, BLACK);
// }

static void	*render_strip(void *arg)
{
	t_threads_data	*td = (t_threads_data *)arg;
	t_fractal *f = td->f;
	
	int y = td->start_y;
	while(y < td->end_y)
	{
		int x = 0;
		while (x < WIDTH)
		{
			t_complex	z;
			t_complex	c;
			int i = 0;
			z.x = map(x, -2, 2, 0, WIDTH) * f->zoom + f->shift_x;
			z.y = map(y, -2, 2, 0, HEIGHT) * f->zoom + f->shift_y;
			mandel_vs_julia(&z, &c, f);
			while (i < f->iterations_definition)
			{
				z = sum_complex(square_complex(z), c);
				if ((z.x * z.x + z.y * z.y) > f->escape_value)
					break ;
				i++;
			}
			int	color = get_color(i, f->iterations_definition);
			my_pixel_put(x, y, f->img, color);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	fractal_render(t_fractal *f)
{
	pthread_t	threads[THREADS];
	t_threads_data	td[THREADS];
	
	int i = 0;
	while (i < THREADS)
	{
		td[i].f = f;
		td[i].start_y = i * (HEIGHT / THREADS);
		td[i].end_y = (i + 1) * (HEIGHT / THREADS);
		td[i].end_y = (i + 1) * (HEIGHT / THREADS);
		pthread_create(&threads[i], NULL, render_strip, &td[i]);		
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}
