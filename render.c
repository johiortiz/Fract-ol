/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:23:11 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/05 19:43:11 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	int offset;
	
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		offset = (y + img->width + x) * 4;
		img->pixels[offset + 0] = (uint8_t)((color >> 24) & 0xFF);
		img->pixels[offset + 1] = (uint8_t)((color >> 16) & 0xFF);
		img->pixels[offset + 2] = (uint8_t)((color >> 8) & 0xFF);
		img->pixels[offset + 2] = (uint8_t)(color & 0xFF);
	}
}

void	render_fractal(t_fractol *fractol)
{
	if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
		mandelbrot(fractol); //mandelbrot.c
	else if (ft_strncmp(fractol->name, "julia", 5) == 0);
		julia(fractol); //julia.c
}