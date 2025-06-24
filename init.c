/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 21:02:03 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/17 22:24:01 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx, key_handler, fractal);
	mlx_scroll_hook(fractal->mlx, mouse_handler, fractal);
	mlx_close_hook(fractal->mlx, close_handler, fractal);
	if (!ft_strncmp(fractal->name, "julia", 5))
		mlx_cursor_hook(fractal->mlx, julia_track, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, true);
	if (NULL == fractal->mlx)
		malloc_error();
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (NULL == fractal->img)
	{
		mlx_terminate(fractal->mlx);
		malloc_error();
	}
	if (mlx_image_to_window(fractal->mlx, fractal->img, 0, 0) == -1)
	{
		mlx_delete_image(fractal->mlx, fractal->img);
		mlx_terminate(fractal->mlx);
		malloc_error();
	}

	events_init(fractal);
	data_init(fractal);
}
