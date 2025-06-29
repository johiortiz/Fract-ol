/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:41:43 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/28 16:44:47 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter, int shift)
{
	int	ci;
	int	r;
	int	g;
	int	b;

	if (iter == max_iter)
		return (0x000000FF);
	ci = (iter * 255) / max_iter;
	r = (ci * (shift * 3 + 5)) % 256;
	g = (ci * (shift * 7 + 3)) % 256;
	b = (ci * (shift * 11 + 1)) % 256;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}
