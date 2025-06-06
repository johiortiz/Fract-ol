/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:42:16 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/06 13:46:14 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *fractol)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while ( x < WIDTH)
		{
			color = (y * 255 / HEIGHT) << 24 | (x * 255 / WIDTH) << 8 | 0xFF000000 | 0xFF;
			put_pixel(fractol->img, x, y, color);
			x++;
		}
		y++;
	}
}