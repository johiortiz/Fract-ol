/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:34:25 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 01:13:53 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <signal.h>

static t_fractal	*g_fractal = NULL;

static void	signal_handler(int sig)
{
	(void)sig;
	if (g_fractal)
	{
		cleanup_fractal(g_fractal);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
		(ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		g_fractal = &fractal;
		signal(SIGINT, signal_handler);
		signal(SIGTERM, signal_handler);
		
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