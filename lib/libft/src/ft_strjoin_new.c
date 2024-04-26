/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:08:05 by recarlie          #+#    #+#             */
/*   Updated: 2022/06/07 15:27:01 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Malloc and return a new string, resulting of concatenation of s1 and
 * s2.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin_new(char *s1, char *s2, int free1, int free2)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	result = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!result)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j])
		result[i + j] = s2[j];
	result[i + j] = '\0';
	if (free1)
		free(s1);
	if (free2)
		free(s2);
	return (result);
}
