/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:23:41 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/30 12:25:23 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert an integer in it's binary representation, malloc'ed in a
 * string.
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itob(int n)
{
	char	*binary;
	int		limit;

	limit = 32;
	binary = (char *)ft_calloc(33, sizeof(char));
	if (!binary)
		return (NULL);
	binary[limit] = '\0';
	limit--;
	while (limit >= 0)
	{
		binary[limit] = n % 2 + '0';
		n = n / 2;
		limit--;
	}
	return (binary);
}
