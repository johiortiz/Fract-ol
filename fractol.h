/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:53:01 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/05 19:40:06 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>


# define WIDTH 800
# define HEIGHT 800
# define TITLE "Fractt-ol"

# define KEY_ESCAPE MLX_KEY_ESCAPE
# define KEY_LEFT MLX_KEY_LEFT
# define KEY_RIGHT MLX_KEY_RIGHT
# define KEY_UP MLX_KEY_UP
# define KEY_DOWN MLX_KEY_DOWN
# define MOUSE_SCROLL_UP MLX_SCROLL_UP
# define MOUSE_SCROLL_DOWN MLX_SCROLL_DOWN

typedef struct	s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*name;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	int			max_iterations;
	double		zoom_factor;
	double		julia_c_real;
	double		julia_c_imag;
}	t_fractol;

void    ft_print_usage(void);
void    ft_error_exit(const char *msg);
double	ft_atof(const char *str);
void	put_pixel(mlx_image_t *img, int x, int y, int color);

#endif