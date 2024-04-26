/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:19:28 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/05 17:27:30 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare the two strings 's1' and 's2' for at most 'n' characters.
 * 
 * @param s1 
 * @param s2 
 * @param n Difference between first pair of different characters.
 * @return int 
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((t_byte)s1[i] - (t_byte)s2[i]);
		i++;
	}
	if (s1[i])
		return ((t_byte)s1[i] - (t_byte)s2[i]);
	if (s2[i] == '\0')
		return (0);
	return (-(t_byte)s2[i]);
}
