/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:55:31 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:35:16 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * /!\ Memory areas must NOT overlap.
 * 
 * @param dst Destination area.
 * @param src Source area.
 * @param n Max amount of bytes copied.
 * @return void* 
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	t_byte	*dst_ptr;
	t_byte	*src_ptr;

	i = 0;
	if ((!dst && !src) || !n)
		return (dst);
	dst_ptr = (t_byte *)dst;
	src_ptr = (t_byte *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst_ptr);
}
