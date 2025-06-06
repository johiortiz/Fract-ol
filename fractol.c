/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 04:37:41 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/06 13:17:18 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char **argv)
{
    t_fractol fractol;
    
    if (argc < 2)
        ft_print_usage();

    fractol.name = argv[1];

    if (ft_strncmp(fractol.name, "mandelbrot", 10) == 0)
    {
        if (argc != 2)
            ft_print_usage();
    }
    else if (ft_strncmp(fractol.name, "julia", 5) == 0)
    {
        if (argc != 4)
            ft_print_usage();
        fractol.julia_c_real = ft_atof(argv[2]);
        fractol.julia_c_imag = ft_atof(argv[3]);
    }
    else
        ft_print_usage();
    fractol_init(&fractol);
    fractol.mlx = ml_init(WIDTH, HEIGHT, TITLE, false);
    if (!fractol.img)
        ft_error_exit("Failed to initialize MLX42.");
    fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
    if (!fractol.img)
    {
        mlx_terminate(fractol_mlx);
        ft_error_exit("Failed to create MLX image.");
    }
	mlx_key_hook(fractol.mlx, handle_input, &fractol);
	mlx_scroll_hook(fractol.mlx, handle_scroll, &fractol);
	mlx_close_hook(fractol.mlx, mlx_close_hook_wrapper, &fractol);
	render_fractal(&fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
    return (0);
}
