/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:06:58 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:18:42 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return an allocated memory and set every memory space to 0.
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size)
{
	t_byte			*memory;

	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * size);
	return (memory);
}
