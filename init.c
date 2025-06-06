/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:18:33 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/06 13:25:52 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->max_iterations = 50;
	if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
	{
		fractol->min_real = -2.0;
		fractol->max_real = 1.0;
		fractol->min_imag = -1.5;
		fractol->max_imag = 1.5;
	}
	else if (ft_strncmp(fractol->name, "julia", 5) == 0)
	{
		fractol->min_real = -2.0;
		fractol->max_real = 2.0;
		fractol->min_imag = -2.0;
		fractol->max_imag = 2.0;
	}
	fractol->zoom_factor = (fractol->max_real - fractol->min_real) / WIDTH;
}