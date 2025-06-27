/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:54:39 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/26 23:07:28 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_fractal *f)
{
	int	x;
	int	y;
	uint32_t *pixels = (uint32_t *)f->img->pixels;
	
	// Renderizado completo
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strncmp(f->type, "mandelbrot", 10))
				pixels[y * WIDTH + x] = draw_mandelbrot(f, x, y);
			else
				pixels[y * WIDTH + x] = draw_julia(f, x, y);
			x++;
		}
		y++;
	}
	f->need_render = false;
}

// Preview rápido de baja resolución durante interacciones
void	fractal_render_preview(t_fractal *f)
{
	int	x, y;
	uint32_t *pixels = (uint32_t *)f->img->pixels;
	int	step = 4; // Renderizar cada 4 píxeles
	
	// Renderizado de baja resolución
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			uint32_t color;
			if (!ft_strncmp(f->type, "mandelbrot", 10))
				color = draw_mandelbrot(f, x, y);
			else
				color = draw_julia(f, x, y);
			
			// Rellenar bloque de píxeles
			int dy = 0;
			while (dy < step && (y + dy) < HEIGHT)
			{
				int dx = 0;
				while (dx < step && (x + dx) < WIDTH)
				{
					pixels[(y + dy) * WIDTH + (x + dx)] = color;
					dx++;
				}
				dy++;
			}
			x += step;
		}
		y += step;
	}
}

// Renderizar solo una línea para mantener fluidez
void	fractal_render_line(t_fractal *f)
{
	int	x;
	uint32_t *pixels = (uint32_t *)f->img->pixels;
	int	step = 1;
	
	if (f->current_y >= HEIGHT)
	{
		f->current_y = 0;
		f->need_render = false;
		return;
	}
	
	// Renderizado adaptativo: usar step más grande durante interacciones
	if (f->mouse_down)
		step = 4; // Saltar píxeles para preview rápido
	
	x = 0;
	while (x < WIDTH)
	{
		uint32_t color;
		if (!ft_strncmp(f->type, "mandelbrot", 10))
			color = draw_mandelbrot(f, x, f->current_y);
		else
			color = draw_julia(f, x, f->current_y);
		
		// Rellenar píxeles según el step
		int i = 0;
		while (i < step && (x + i) < WIDTH)
		{
			pixels[f->current_y * WIDTH + x + i] = color;
			i++;
		}
		x += step;
	}
	f->current_y++;
}

// Zoom fluido por escalado sin recálculo
void	scaled_zoom_render(t_fractal *f, double zoom_factor)
{
	int	x, y;
	uint32_t *pixels = (uint32_t *)f->img->pixels;
	uint32_t *base_pixels = (uint32_t *)f->base_img->pixels;
	int	center_x = WIDTH / 2;
	int	center_y = HEIGHT / 2;
	
	// Limpiar imagen actual
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixels[y * WIDTH + x] = 0x000000FF; // Negro por defecto
			x++;
		}
		y++;
	}
	
	// Escalar imagen base con interpolación mejorada
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// Calcular posición en imagen base
			double src_x_f = center_x + (x - center_x) / zoom_factor;
			double src_y_f = center_y + (y - center_y) / zoom_factor;
			int src_x = (int)src_x_f;
			int src_y = (int)src_y_f;
			
			// Verificar límites con un poco de margen
			if (src_x >= 1 && src_x < (WIDTH-1) && src_y >= 1 && src_y < (HEIGHT-1))
			{
				// Interpolación bilineal simple
				double fx = src_x_f - src_x;
				double fy = src_y_f - src_y;
				
				if (fx < 0.5 && fy < 0.5)
					pixels[y * WIDTH + x] = base_pixels[src_y * WIDTH + src_x];
				else if (fx >= 0.5 && fy < 0.5)
					pixels[y * WIDTH + x] = base_pixels[src_y * WIDTH + (src_x + 1)];
				else if (fx < 0.5 && fy >= 0.5)
					pixels[y * WIDTH + x] = base_pixels[(src_y + 1) * WIDTH + src_x];
				else
					pixels[y * WIDTH + x] = base_pixels[(src_y + 1) * WIDTH + (src_x + 1)];
			}
			x++;
		}
		y++;
	}
}

// Copiar imagen actual a imagen base tras terminar zoom
void	update_base_image(t_fractal *f)
{
	int	x, y;
	uint32_t *pixels = (uint32_t *)f->img->pixels;
	uint32_t *base_pixels = (uint32_t *)f->base_img->pixels;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			base_pixels[y * WIDTH + x] = pixels[y * WIDTH + x];
			x++;
		}
		y++;
	}
	f->base_zoom = f->zoom;
}
