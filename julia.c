/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:42:16 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 20:15:16 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	draw_julia(t_fractal *f, int x, int y)
{
	t_complex	z;
	int			iter;
	double		zr_sq;
	double		zi_sq;
	double		temp;

	z.re = ((x + 0.5) - WIDTH / 2.0) / (0.4 * f->zoom * WIDTH) + f->offset_x;
	z.im = ((y + 0.5) - HEIGHT / 2.0) / (0.4 * f->zoom * HEIGHT) + f->offset_y;
	iter = 0;
	while (iter < f->max_iter)
	{
		zr_sq = z.re * z.re;
		zi_sq = z.im * z.im;
		if (zr_sq + zi_sq > 4.0)
			break ;
		temp = zr_sq - zi_sq + f->julia_c.re;
		z.im = 2.0 * z.re * z.im + f->julia_c.im;
		z.re = temp;
		iter++;
	}
	return (get_color(iter, f->max_iter, f->color_shift));
}
