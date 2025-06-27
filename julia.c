/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:08:14 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 00:14:56 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	draw_julia(t_fractal *f, int x, int y)
{
	t_complex	z;
	int		iter;
	double	zr_sq, zi_sq;
	double	temp;

	// Calcular coordenadas iniciales con rango ajustado para Julia
	z.re = ((x + 0.5) - WIDTH / 2.0) / (0.4 * f->zoom * WIDTH) + f->offset_x;
	z.im = ((y + 0.5) - HEIGHT / 2.0) / (0.4 * f->zoom * HEIGHT) + f->offset_y;
	
	// Optimización: evitar funciones y cálculos redundantes
	iter = 0;
	while (iter < f->max_iter)
	{
		zr_sq = z.re * z.re;
		zi_sq = z.im * z.im;
		
		// Condición de escape optimizada
		if (zr_sq + zi_sq > 4.0)
			break;
		
		// Iteración Julia optimizada (inline)
		temp = zr_sq - zi_sq + f->julia_c.re;
		z.im = 2.0 * z.re * z.im + f->julia_c.im;
		z.re = temp;
		
		iter++;
	}
	return (get_color(iter, f->max_iter, f->color_shift));
}

