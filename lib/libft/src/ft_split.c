/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:23:46 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:40:46 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_sep(char const *s, char c)
{
	int		count;

	if (s[0] == '\0')
		return (-1);
	while (*s && *s == c)
		s++;
	count = 0;
	while (1)
	{
		while (*s && *s != c)
			s++;
		if (*s == '\0')
			break ;
		else
			count++;
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
	}
	if (count == 1)
		return (0);
	if (*(s - 1) == c)
		count--;
	return (count);
}

static size_t	get_size(const char **s, char c)
{
	const char	*str;
	size_t		size;

	str = *s;
	size = 0;
	while (*str && *str == c)
		str++;
	while (*str && *str != c)
	{
		str++;
		size++;
	}
	return (size);
}

static char	**ft_free(char **result, size_t i)
{
	while (i > 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}

/**
 * @brief Malloc and return an array of strings obtained by splitting 's' at
 * every occurence of 'c' character. Array is terminated with NULL.
 * 
 * @param s String.
 * @param c Delimiter.
 * @return char** 
 */
char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**result;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	result = (char **)ft_calloc(sizeof(char *), (count_sep(s, c) + 3));
	if (!result)
		return (NULL);
	while (count_sep(s, c) >= 0)
	{
		while (*s == c)
			s++;
		size = get_size(&s, c);
		if (!size)
			break ;
		result[i] = (char *)ft_calloc(sizeof(char), (size + 1));
		if (!result[i])
			return (ft_free(result, i));
		ft_strlcpy(result[i++], s, size + 1);
		s += size;
	}
	result[i] = NULL;
	return (result);
}
