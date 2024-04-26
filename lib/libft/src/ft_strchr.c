/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:15:55 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:41:39 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return a pointer to the first occurence of the character 'c' in the
 * string 's'. (NULL if no occurence)
 * 
 * @param s String.
 * @param c Character.
 * @return char* 
 */
char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;

	s_ptr = (char *)s;
	while (*s_ptr && *s_ptr != (t_byte)c)
		s_ptr++;
	if (*s_ptr == (t_byte)c)
		return (s_ptr);
	return (0);
}
