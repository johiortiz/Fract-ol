/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:31:53 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/05 19:04:58 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	double	res;
	double	power;
	int		sign;
	int		i;

	res = 0.0;
	power = 1.0;
	sign = 1;
	i = 0;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '-')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			power /= 10.0;
			res = res + (str[i] - '0') * power;
			i++;
		}
	}
	return (sign * res);
}

void    ft_print_usage(void)
{
    fprintf(stderr, "Usage: ./fractol <mandelbrot | julia>\n");
    exit(EXIT_FAILURE);
}

void    ft_error_exit(const char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}
