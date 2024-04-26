/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:43:23 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:31:19 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return a pointer to the matching byte or NULL if the character isn't
 * in the given memory area.
 * 
 * @param s Memory area.
 * @param c Searched character.
 * @param n Size of the said area.
 * @return void* 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	*s_ptr;
	size_t	i;

	if (!n)
		return (0);
	s_ptr = (t_byte *)s;
	i = 0;
	while (i < n)
	{
		if (s_ptr[i] != (t_byte)c)
			i++;
		else
			return (s_ptr + i);
	}
	return (0);
}
