/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:26:12 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/28 16:15:29 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_fractal *f)
{
	uint32_t	*pixels;
	int			x;
	int			y;

	pixels = (uint32_t *)f->img->pixels;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(f->type, "mandelbrot", 10))
				pixels[y * WIDTH + x] = draw_mandelbrot(f, x, y);
			else
				pixels[y * WIDTH + x] = draw_julia(f, x, y);
			x++;
		}
		y++;
	}
	f->need_render = false;
}

void	fractal_render_preview(t_fractal *f)
{
	uint32_t	*pixels;
	uint32_t	color;
	int			x;
	int			y;
	int			i;

	pixels = (uint32_t *)f->img->pixels;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(f->type, "mandelbrot", 10))
				color = draw_mandelbrot(f, x, y);
			else
				color = draw_julia(f, x, y);
			i = -1;
			while (++i < 16)
				if ((y + i / 4) < HEIGHT && (x + i % 4) < WIDTH)
					pixels[(y + i / 4) * WIDTH + (x + i % 4)] = color;
			x += 4;
		}
		y += 4;
	}
}

void	fractal_render_line(t_fractal *f)
{
	uint32_t	*pixels;
	uint32_t	color;
	int			x;
	int			i;

	pixels = (uint32_t *)f->img->pixels;
	if (f->current_y >= HEIGHT)
	{
		f->current_y = 0;
		f->need_render = false;
		return ;
	}
	x = 0;
	while (x < WIDTH)
	{
		if (!ft_strncmp(f->type, "mandelbrot", 10))
			color = draw_mandelbrot(f, x, f->current_y);
		else
			color = draw_julia(f, x, f->current_y);
		i = -1;
		while (++i < 1 + 3 * f->mouse_down && (x + i) < WIDTH)
			pixels[f->current_y * WIDTH + x + i] = color;
		x += 1 + 3 * f->mouse_down;
	}
	f->current_y++;
}

void	scaled_zoom_render(t_fractal *f, double z)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			((uint32_t *)f->img->pixels)[y * WIDTH + x] = 0x000000FF;
			if ((int)(WIDTH / 2 + (x - WIDTH / 2) / z) >= 0 && (int)(WIDTH / 2
					+ (x - WIDTH / 2) / z) < WIDTH && (int)(HEIGHT / 2 + (y
						- HEIGHT / 2) / z) >= 0 && (int)(HEIGHT / 2 + (y
						- HEIGHT / 2) / z) < HEIGHT)
				((uint32_t *)f->img->pixels)[y * WIDTH
					+ x] = ((uint32_t *)f->base_img->pixels)[(int)(HEIGHT / 2
						+ (y - HEIGHT / 2) / z) *WIDTH + (int)(WIDTH / 2 + (x
							- WIDTH / 2) / z)];
		}
	}
}

void	update_base_image(t_fractal *f)
{
	uint32_t	*base_pixels;
	uint32_t	*pixels;
	int			x;
	int			y;

	base_pixels = (uint32_t *)f->base_img->pixels;
	pixels = (uint32_t *)f->img->pixels;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			base_pixels[y * WIDTH + x] = pixels[y * WIDTH + x];
			x++;
		}
		y++;
	}
	f->base_zoom = f->zoom;
}
