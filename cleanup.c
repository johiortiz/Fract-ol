/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:42:29 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/28 16:22:45 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup_fractal(t_fractal *f)
{
	if (!f || !f->mlx)
		return ;
	mlx_terminate(f->mlx);
	f->mlx = NULL;
	f->img = NULL;
	f->base_img = NULL;
}
