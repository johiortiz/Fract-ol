/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:37:41 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/18 12:14:52 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int ac, char **av)
{
	t_fractal fractal;
	
   if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
      || (4 == ac && !ft_strncmp(av[1], "julia", 5)))
   {
		fractal.name = av[1];
      if (!ft_strncmp(av[1], "julia", 5))
      {
         fractal.julia_x = atodbl(av[2]);
         fractal.julia_y = atodbl(av[3]);
      }
      fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx);
   }
   else
   {
	   putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
   }
   return (0);
}
