/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:59:09 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/26 23:50:45 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	draw_mandelbrot(t_fractal *f, int x, int y)
{
	t_complex	c;
	t_complex	z = {0, 0};
	int	iter;
	double	zr_sq, zi_sq;
	double	temp;

	// Precalcular coordenadas del plano complejo
	c.re = ((x + 0.5) - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->offset_x;
	c.im = ((y + 0.5) - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->offset_y;
	
	// Optimización: evitar funciones y cálculos redundantes
	iter = 0;
	while (iter < f->max_iter)
	{
		zr_sq = z.re * z.re;
		zi_sq = z.im * z.im;
		
		// Condición de escape optimizada
		if (zr_sq + zi_sq > 4.0)
			break;
		
		// Iteración mandelbrot optimizada (inline)
		temp = zr_sq - zi_sq + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = temp;
		
		iter++;
	}
	return (get_color(iter, f->max_iter, f->color_shift));
}
