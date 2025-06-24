/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 01:29:12 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/24 18:13:22 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    close_handler(void *param)
{
    t_fractal *f = (t_fractal *)param;
    mlx_delete_image(f->mlx, f->img);
    mlx_terminate(f->mlx);
    exit(EXIT_SUCCESS);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
    t_fractal *f = (t_fractal *)param;
    
    if (keydata.action == MLX_PRESS)
    {
        if (keydata.key == MLX_KEY_ESCAPE)
            close_handler(f);
        if (keydata.key == MLX_KEY_LEFT)
            f->shift_x -= (0.1 * f->zoom);
        else if (keydata.key == MLX_KEY_RIGHT)
            f->shift_x += (0.1 * f->zoom);
        else if (keydata.key == MLX_KEY_UP)
            f->shift_y -= (0.1 * f->zoom);
        else if (keydata.key == MLX_KEY_DOWN)
            f->shift_y += (0.1 * f->zoom);
        else if (keydata.key == MLX_KEY_M)
            f->iterations_definition += 10;
        else if (keydata.key == MLX_KEY_MINUS)
            f->iterations_definition -= 10;
        fractal_render(f);
    }
}

void mouse_handler(double xdelta, double ydelta, void *param)
{
	t_fractal *f = (t_fractal *)param;
	double	mx = f->mouse_x;
	double	my = f->mouse_y;
	
	(void)xdelta;
    
    double	old_x = (map(mx, -2, 2, 0, WIDTH) * f->zoom) + f->shift_x;
    double	old_y = (map(my, -2,+2, 0, HEIGHT) * f->zoom) + f->shift_y;
    if (ydelta > 0)
        f->zoom *= 0.95;
    else if (ydelta < 0)
        f->zoom *= 1.05;
    double	new_x = (map(mx, +-2, 2, 0, WIDTH) * f->zoom) + f->shift_x;
    double	new_y = (map(my, +-2, 2, 0, HEIGHT) * f->zoom) + f->shift_y;
    f->shift_x += old_x - new_x;
    f->shift_y += old_y - new_y;
    fractal_render(f);
}

void	julia_track(double xpos, double ypos, void *param)
{
    t_fractal *f = (t_fractal *)param;
	
    f->mouse_x = xpos;
	f->mouse_y = ypos;
	if (!ft_strncmp(f->name, "julia", 5))
	{
		f->julia_x = (map(xpos, -2, +2, 0, WIDTH) * f->zoom) + f->shift_x;
		f->julia_y = (map(ypos, -2, +2, 0, HEIGHT) * f->zoom) + f->shift_y;
		fractal_render(f);
	}
}
