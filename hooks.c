/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:47:02 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/06 13:53:42 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_input(mlx_key_dat_t keydata, void *param)
{
	t_fractol	*fractol;
	
	fractol = (t_fractol *)param;
	if (keydata.key == KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	
	fractol = (t_fractol *)param;
	if (ydelta > 0)
		ft_putendl_fd("Zoom In!", 1);
	else if (ydelta < 0)
		ft_putendl_fd("Zoom Out!", 1);
}

void	mlx_close_hook_wrapper(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	mlx_terminate(frctol->mlx);
	exit(EXIT_SUCCESS);
}