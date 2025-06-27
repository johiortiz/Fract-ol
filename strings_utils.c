/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 20:40:17 by johyorti          #+#    #+#             */
/*   Updated: 2025/06/26 20:57:49 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strncmp(char *s1, char *s2, int n)
{
    if (s1 == NULL || s2 == NULL || n <= 0)
        return (0);
    while (*s1 == *s2 && n > 1 && *s1 != '\0')
    {
        ++s1;
        ++s2;
        --n;
    }
    return (*s1 - *s2);
}

void    ft_putstr_fd(char *s, int fd)
{
    if (NULL == s || fd < 0)
        return ;
    if (*s != '\0')
    {
        if (write(fd, s, 1) == -1)
            return;
        ft_putstr_fd(s + 1, fd);
    }
}

double  ft_atodbl(char *s)
{
    long    integer_part;
    double  fractional_part;
    double  pow;
    int     sign;

    integer_part = 0;
    fractional_part = 0;
    sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
