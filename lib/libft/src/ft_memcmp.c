/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:02:16 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:33:46 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares the first n bytes (as unsigned char) of the memory
 * areas s1 and s2.
 * 
 * @param s1 Memory space 1.
 * @param s2 Memory space 2.
 * @param n Maximum amount of bytes compared.
 * @return int - Difference between the first different pair of bytes.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	t_byte	*s1_ptr;
	t_byte	*s2_ptr;

	i = 0;
	s1_ptr = (t_byte *)s1;
	s2_ptr = (t_byte *)s2;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return ((int)(s1_ptr[i] - s2_ptr[i]));
		i++;
	}
	return (0);
}
