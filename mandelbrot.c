/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:36:12 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 20:25:53 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	draw_mandelbrot(t_fractal *f, int x, int y)
{
	t_complex	c;
	t_complex	z;
	double		z_re_prev;
	int			iter;

	z = (t_complex){0, 0};
	c.re = ((x + 0.5) - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
	c.im = ((y + 0.5) - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
	iter = 0;
	while (iter < f->max_iter)
	{
		if (z.re * z.re + z.im * z.im > 4.0)
			break ;
		z_re_prev = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z_re_prev * z.im + c.im;
		iter++;
	}
	return (get_color(iter, f->max_iter, f->color_shift));
}
