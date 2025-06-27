/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:29:37 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 00:02:32 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	double	old_zoom;

	(void)xdelta;
	f = (t_fractal *)param;
	old_zoom = f->zoom;
	
	if (ydelta > 0)
		f->zoom *= 1.05; // Zoom más pequeño para mayor control
	else if (ydelta < 0)
		f->zoom /= 1.05;
	else
		return;
	
	// Ajustar offset para zoom centrado en mouse
	f->offset_x += (f->mouse_x - WIDTH / 2.0) / (WIDTH * old_zoom)
				 - (f->mouse_x - WIDTH / 2.0) / (WIDTH * f->zoom);
	f->offset_y += (f->mouse_y - HEIGHT / 2.0) / (HEIGHT * old_zoom)
				 - (f->mouse_y - HEIGHT / 2.0) / (HEIGHT * f->zoom);
	
	// Preview inmediato durante zoom
	fractal_render(f);
	f->is_zooming = true;
	f->scrolling_this_frame = true;
}

static void	keyhook(mlx_key_data_t key, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(f->mlx);
	else if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
	{
		f->color_shift = (f->color_shift + 1) % 8;
		f->need_render = true;
		f->current_y = 0;
	}
	else if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
	{
		f->offset_x -= 0.1 / f->zoom;
		f->need_render = true;
		f->current_y = 0;
	}
	else if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
	{
		f->offset_x += 0.1 / f->zoom;
		f->need_render = true;
		f->current_y = 0;
	}
	else if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
	{
		f->offset_y -= 0.1 / f->zoom;
		f->need_render = true;
		f->current_y = 0;
	}
	else if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
	{
		f->offset_y += 0.1 / f->zoom;
		f->need_render = true;
		f->current_y = 0;
	}
	else if (key.key == MLX_KEY_EQUAL && key.action == MLX_PRESS)
	{
        f->max_iter += 10;
		f->need_render = true;
		f->current_y = 0;
	}
    else if (key.key == MLX_KEY_MINUS && key.action == MLX_PRESS)
    {
		if (f->max_iter > 10)
			f->max_iter -= 10;
		f->need_render = true;
		f->current_y = 0;
	}
}

static void	mousehook(mouse_key_t button, action_t action, modifier_key_t mod, void *param)
{
	t_fractal	*f = (t_fractal *)param;
	(void)mod;

	if (button == MLX_MOUSE_BUTTON_LEFT)
	{
		if (action == MLX_PRESS)
		{
			f->mouse_down = true;
			f->mouse_down_x = f->mouse_x;
			f->mouse_down_y = f->mouse_y;
			f->drag_start_offset_x = f->offset_x;
			f->drag_start_offset_y = f->offset_y;
		}
		else if (action == MLX_RELEASE)
		{
			f->mouse_down = false;
			fractal_render(f); // Renderizado completo inmediato tras drag
		}
	}
}

static void	cursorhook(double xpos, double ypox, void *param)
{
	t_fractal	*f = (t_fractal *)param;
	f->mouse_x = xpos;
	f->mouse_y = ypox;

	if (f->mouse_down)
	{
		double	dx = (xpos - f->mouse_down_x) / (WIDTH * f->zoom);
		double	dy = (ypox - f->mouse_down_y) / (HEIGHT * f->zoom);
		f->offset_x = f->drag_start_offset_x - dx;
		f->offset_y = f->drag_start_offset_y - dy;
		f->need_render = true;
		f->current_y = 0;
	}
}

static void	loop_hook(void *param)
{
	t_fractal	*f = (t_fractal *)param;
	static int frame_count = 0;
	static int zoom_timeout = 0;
	
	// Renderizado en alta calidad inmediato tras terminar scroll
	if (f->is_zooming && !f->scrolling_this_frame)
	{
		fractal_render(f);
		f->is_zooming = false;
		zoom_timeout = 0;
	}
	else if (f->is_zooming)
	{
		zoom_timeout++;
		if (zoom_timeout > 60) // ~1 segundo sin zoom (backup)
		{
			fractal_render(f);
			f->is_zooming = false;
			zoom_timeout = 0;
		}
	}
	else
	{
		zoom_timeout = 0;
		// Renderizado incremental normal
		if (f->need_render)
		{
			// Renderizado rápido durante drag, normal sin drag
			if (f->mouse_down)
				fractal_render(f);
			else
			{
				int lines_per_frame = 24;
				int i = 0;
				while (i < lines_per_frame && f->current_y < HEIGHT)
				{
					fractal_render_line(f);
					i++;
				}
				// Si hemos terminado
				if (f->current_y >= HEIGHT)
				{
					f->need_render = false;
					f->current_y = 0;
				}
			}
		}
	}
	f->scrolling_this_frame = false;
	frame_count++;
}

void	set_hooks(t_fractal *f)
{
	mlx_scroll_hook(f->mlx, scrollhook, f);
	mlx_key_hook(f->mlx, keyhook, f);
	mlx_cursor_hook(f->mlx, cursorhook, f);
	mlx_mouse_hook(f->mlx, mousehook, f);
	mlx_loop_hook(f->mlx, loop_hook, f);
}