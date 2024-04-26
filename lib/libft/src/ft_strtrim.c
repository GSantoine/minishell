/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:15:18 by recarlie          #+#    #+#             */
/*   Updated: 2022/04/19 16:38:55 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	new_strlen(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	if (i == j)
		return (0);
	while (s1[j - 1] && is_in_set(s1[j - 1], set))
		j--;
	return (j - i);
}

/**
 * @brief Malloc and return a copy of 's1' without characters specified in 'set'.
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s2_len;
	char	*s2;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (s1[0] == '\0')
		s2_len = 0;
	else
		s2_len = new_strlen(s1, set);
	s2 = (char *)ft_calloc(sizeof(char), (s2_len + 2));
	if (!s2)
		return (NULL);
	while (is_in_set(*s1, set))
		s1++;
	while (i < s2_len)
	{
		s2[i] = *s1;
		s1++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
