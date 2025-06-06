/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 21:38:40 by johyorti          #+#    #+#             */
/*   Updated: 2024/10/09 19:27:23 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		n *= -1;
		count = 1;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	len = count_digit(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	num = ((str[len] = '\0'), n);
	if (n < 0)
		str[0] = ((num *= -1), '-');
	if (n == 0)
		str[0] = 48;
	while (num > 0)
		num /= ((str[--len] = (num % 10) + 48), 10);
	return (str);
}
