/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:14:23 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/26 20:19:49 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double val, double min_out, double max_out, double min_in, double max_in)
{
	return (val - min_in) / (max_in - min_in) * (max_out - min_out) + min_out;
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