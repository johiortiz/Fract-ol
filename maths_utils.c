/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:41:15 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 20:53:43 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double val, t_range in_range, t_range out_range)
{
	return ((val - in_range.min) / (in_range.max - in_range.min)
		* (out_range.max - out_range.min) + out_range.min);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re + b.re;
	res.im = a.im + b.im;
	return (res);
}

t_complex	complex_square(t_complex z)
{
	t_complex	res;

	res.re = z.re * z.re - z.im * z.im;
	res.im = 2 * z.re * z.im;
	return (res);
}
