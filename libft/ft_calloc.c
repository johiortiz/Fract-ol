/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 04:15:53 by johyorti          #+#    #+#             */
/*   Updated: 2024/10/09 15:05:36 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tsize;

	tsize = nmemb * size;
	if (nmemb != 0 && tsize / nmemb != size)
		return (NULL);
	ptr = malloc(tsize);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, tsize);
	return (ptr);
}
