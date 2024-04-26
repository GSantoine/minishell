/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:16:51 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:49:04 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate the first occurence of 'needle' in 'str', where not more than
 * 'len' characters are searched.
 * 
 * @param str 
 * @param needle 
 * @param len 
 * @return char* 
 */
char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		verif;

	verif = (int)len;
	if (verif < 0 && ft_strlen(needle) >= 1 && *str)
		len = ft_strlen(str) - 1;
	if (ft_strlen(str) < ft_strlen(needle) || (!len && ft_strlen(needle) > 0))
		return (0);
	if (ft_strncmp(str, needle, len) == 0 || !needle || *needle == '\0')
		return ((char *)str);
	j = 1;
	while (*str && j < len)
	{
		i = 0;
		while (str[i] && needle[i] && str[i] == needle[i] && j <= len)
		{
			i++;
			if (needle[i] == '\0' && j + i <= len + 1)
				return ((char *)(str));
		}
		j++;
		str++;
	}
	return (0);
}
