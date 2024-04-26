/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:48:43 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:18:37 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Set every spaces to 0 in pointed area.
 * 
 * @param s Pointer to the allocated memory.
 * @param n Size of the allocated memory.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	t_byte	*s_ptr;

	i = 0;
	s_ptr = (t_byte *)s;
	while (i < n)
	{
		s_ptr[i] = 0;
		i++;
	}
}
