/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:43:58 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:37:22 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fill a memory area with a constant byte (c).
 * 
 * @param b Memory area.
 * @param c Byte.
 * @param len Size of memory area.
 * @return void* 
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	t_byte	*b_ptr;

	i = 0;
	b_ptr = (t_byte *)b;
	while (i < len)
	{
		b_ptr[i] = (t_byte)c;
		i++;
	}
	return (b);
}
