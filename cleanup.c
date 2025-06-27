/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:26:15 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 01:05:26 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup_fractal(t_fractal *f)
{
	if (!f || !f->mlx)
		return;
	
	// mlx_terminate libera automáticamente todas las imágenes
	mlx_terminate(f->mlx);
	f->mlx = NULL;
	f->img = NULL;
	f->base_img = NULL;
} 