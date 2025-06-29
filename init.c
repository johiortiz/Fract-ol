/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:18:33 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/28 16:46:40 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mlx_components(t_fractal *f, const char *title)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, title, false);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->base_img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}

static void	init_default_params(t_fractal *f, char *type)
{
	f->type = type;
	f->zoom = 1.0;
	f->base_zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->max_iter = 80;
	f->color_shift = 0;
	f->mouse_down = false;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->drag_start_offset_x = 0;
	f->drag_start_offset_y = 0;
	f->need_render = true;
	f->is_zooming = false;
	f->current_y = 0;
	f->scrolling_this_frame = false;
}

void	fractal_init(t_fractal *f, int ac, char **av)
{
	(void)ac;
	init_mlx_components(f, av[1]);
	init_default_params(f, av[1]);
	if (!ft_strncmp(f->type, "julia", 5))
	{
		f->julia_c.re = ft_atodbl(av[2]);
		f->julia_c.im = ft_atodbl(av[3]);
		f->offset_x = -0.5;
		f->offset_y = 0.0;
	}
	set_hooks(f);
	fractal_render(f);
	update_base_image(f);
}
