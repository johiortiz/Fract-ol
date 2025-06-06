/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:28:53 by johyorti          #+#    #+#             */
/*   Updated: 2024/10/10 02:09:01 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(char const *s, char c)
{
	size_t	n_word;

	n_word = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			n_word++;
			while (*s && *s != c)
				s++;
		}
	}
	return (n_word);
}

static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

static char	*fill_word(const char **s, char c)
{
	size_t	len;
	char	*word;

	while (**s == c && **s != '\0')
		(*s)++;
	if (**s == '\0')
		return (NULL);
	len = word_len(*s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, *s, len + 1);
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	char	*word;
	size_t	j;
	size_t	len;

	if (!s)
		return (NULL);
	len = word_counter(s, c);
	matrix = (char **)malloc((len + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word = fill_word(&s, c);
		if (word)
			matrix[j++] = word;
		else
			return (ft_free(matrix), matrix = NULL, NULL);
	}
	matrix[j] = NULL;
	return (matrix);
}
