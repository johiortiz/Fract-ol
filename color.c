/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:20:19 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/27 00:10:31 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter, int shift)
{
	// Optimización: evitar operaciones de punto flotante costosas
	if (iter == max_iter)
		return (0x000000FF); // Negro para puntos dentro del conjunto
	
	// Colorear usando operaciones enteras más rápidas
	int color_index = (iter * 255) / max_iter;
	int r, g, b;
	
	switch (shift % 8)
	{
		case 0: // Psicodélico Neon (Azul-Magenta-Cian)
			r = (color_index * 3) % 256;
			g = (color_index * 7) % 256;
			b = 255;
			break;
		case 1: // Fuego Psicodélico (Rojo-Naranja-Magenta)
			r = 255;
			g = (color_index * 2) % 256;
			b = (color_index * 4) % 256;
			break;
		case 2: // Océano Profundo (Azul-Verde-Cian)
			r = (color_index / 4) % 256;
			g = (color_index * 3) % 256;
			b = 255;
			break;
		case 3: // Bosque Místico (Verde-Cian-Azul)
			r = (color_index / 3) % 256;
			g = 255;
			b = (color_index * 2) % 256;
			break;
		case 4: // Púrpura Eléctrico (Magenta-Violeta)
			r = 255;
			g = (color_index / 2) % 256;
			b = (color_index * 3) % 256;
			break;
		case 5: // Arcoíris Psicodélico (Colores vibrantes)
			r = (color_index * 5) % 256;
			g = (color_index * 7) % 256;
			b = (color_index * 11) % 256;
			break;
		case 6: // Plasma (Verde-Neon-Cian)
			r = (color_index / 2) % 256;
			g = 255;
			b = (color_index * 4) % 256;
			break;
		case 7: // Fuego Azul (Azul-Cian-Blanco)
			r = (color_index * 2) % 256;
			g = (color_index * 3) % 256;
			b = 255;
			break;
		default:
			r = (color_index * 3) % 256;
			g = (color_index * 7) % 256;
			b = 255;
			break;
	}
	
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}
