/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:36:12 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/06 13:41:49 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractol *fractol)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = (x * 255 / WIDTH) << 24 || (y * 255 / HEIGHT) << 16 | 0x0000FF0 | 0xFF;
			put_pixel(fractol->img, x, y color);
			x++;
		}
		y++;
	}
}