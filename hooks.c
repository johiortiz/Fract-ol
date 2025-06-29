/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:36:26 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 21:04:38 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_zoom_end(t_fractal *f, int *zoom_timeout)
{
	if (!f->scrolling_this_frame || ++(*zoom_timeout) > 60)
	{
		fractal_render(f);
		f->is_zooming = false;
		*zoom_timeout = 0;
	}
}

static void	handle_incremental_render(t_fractal *f)
{
	int	i;

	i = -1;
	while (++i < 24 && f->current_y < HEIGHT)
		fractal_render_line(f);
	if (f->current_y >= HEIGHT)
	{
		f->need_render = false;
		f->current_y = 0;
	}
}

void	loop_hook(void *param)
{
	t_fractal	*f;
	static int	zoom_timeout = 0;

	f = (t_fractal *)param;
	f->frame_count++;
	if (f->is_zooming)
		handle_zoom_end(f, &zoom_timeout);
	else if (f->need_render)
	{
		zoom_timeout = 0;
		if (f->mouse_down)
			fractal_render(f);
		else
			handle_incremental_render(f);
	}
	f->scrolling_this_frame = false;
}

void	set_hooks(t_fractal *f)
{
	mlx_scroll_hook(f->mlx, scrollhook, f);
	mlx_key_hook(f->mlx, keyhook, f);
	mlx_cursor_hook(f->mlx, cursorhook, f);
	mlx_mouse_hook(f->mlx, mousehook, f);
	mlx_loop_hook(f->mlx, loop_hook, f);
}
