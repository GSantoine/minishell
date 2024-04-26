/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:07:15 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:36:30 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * Memory areas can overlap.
 * 
 * @param dst Destination area.
 * @param src Source area.
 * @param len Size of destination area.
 * @return void* 
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	t_byte	*dst_ptr;
	t_byte	*src_ptr;

	if ((!dst && !src) || !len)
		return (dst);
	dst_ptr = (t_byte *)dst;
	if (!len)
		return (dst_ptr);
	i = -1;
	src_ptr = (t_byte *)src;
	if (dst_ptr <= src_ptr)
		while (++i < len)
			dst_ptr[i] = src_ptr[i];
	else
		while (len-- > 0)
			dst_ptr[len] = src_ptr[len];
	return (dst_ptr);
}
