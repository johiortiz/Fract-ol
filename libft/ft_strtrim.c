/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 02:43:34 by johyorti          #+#    #+#             */
/*   Updated: 2024/10/07 11:19:27 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	if (end <= start)
		return (ft_strdup(""));
	new_str = malloc((end - start + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memmove(new_str, s1 + start, end - start);
	new_str[end - start] = '\0';
	return (new_str);
}
