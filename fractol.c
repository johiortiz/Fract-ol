/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:37:41 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 21:05:54 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	fractal.frame_count = 0;
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal_init(&fractal, ac, av);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
		cleanup_fractal(&fractal);
	}
	else
	{
		ft_putstr_fd("./fractol mandelbrot / julia <Re> <Im>\n", 2);
		return (1);
	}
	return (0);
}
