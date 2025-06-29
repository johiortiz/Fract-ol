/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:47:02 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/28 16:46:20 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;
	double		old_zoom;

	(void)xdelta;
	f = (t_fractal *)param;
	old_zoom = f->zoom;
	if (ydelta > 0)
		f->zoom *= 1.05;
	else if (ydelta < 0)
		f->zoom /= 1.05;
	else
		return ;
	f->offset_x += (f->mouse_x - WIDTH / 2.0) / (WIDTH * old_zoom)
		- (f->mouse_x - WIDTH / 2.0) / (WIDTH * f->zoom);
	f->offset_y += (f->mouse_y - HEIGHT / 2.0) / (HEIGHT * old_zoom)
		- (f->mouse_y - HEIGHT / 2.0) / (HEIGHT * f->zoom);
	fractal_render(f);
	f->is_zooming = true;
	f->scrolling_this_frame = true;
}

void	keyhook(mlx_key_data_t key, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	if (key.action != MLX_PRESS)
		return ;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(f->mlx);
	else if (key.key == MLX_KEY_SPACE)
		f->color_shift = (f->color_shift + 1) % 8;
	else if (key.key == MLX_KEY_LEFT)
		f->offset_x -= 0.1 / f->zoom;
	else if (key.key == MLX_KEY_RIGHT)
		f->offset_x += 0.1 / f->zoom;
	else if (key.key == MLX_KEY_UP)
		f->offset_y -= 0.1 / f->zoom;
	else if (key.key == MLX_KEY_DOWN)
		f->offset_y += 0.1 / f->zoom;
	else if (key.key == MLX_KEY_EQUAL)
		f->max_iter += 10;
	else if (key.key == MLX_KEY_MINUS && f->max_iter > 10)
		f->max_iter -= 10;
	if (key.key != MLX_KEY_ESCAPE)
		f->need_render = true;
	if (key.key != MLX_KEY_ESCAPE)
		f->current_y = 0;
}

void	mousehook(mouse_key_t button, action_t action,
	modifier_key_t mod, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
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
			fractal_render(f);
		}
	}
}

void	cursorhook(double xpos, double ypox, void *param)
{
	t_fractal	*f;
	double		dx;
	double		dy;

	f = (t_fractal *)param;
	f->mouse_x = xpos;
	f->mouse_y = ypox;
	if (f->mouse_down)
	{
		dx = (xpos - f->mouse_down_x) / (WIDTH * f->zoom);
		dy = (ypox - f->mouse_down_y) / (HEIGHT * f->zoom);
		f->offset_x = f->drag_start_offset_x - dx;
		f->offset_y = f->drag_start_offset_y - dy;
		f->need_render = true;
		f->current_y = 0;
	}
}
