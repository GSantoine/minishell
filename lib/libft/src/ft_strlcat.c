/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:41:53 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:44:47 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy and concatenate 'src' at the end of 'dest'.
 * 
 * @param dest Destination.
 * @param src Source.
 * @param dstsize Size of dest.
 * @return size_t 
 */
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	int		i;
	int		j;
	int		test;

	i = 0;
	j = 0;
	test = (int)dstsize;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (test < 0)
		dstsize = dest_len + src_len + 1;
	if (!dstsize || !dest || (dstsize < dest_len))
		return (src_len + dstsize);
	while (dest[i])
		i++;
	while (src[j] && i < (int)dstsize - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest_len + src_len);
}
