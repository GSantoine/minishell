/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:38:31 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:21:17 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return the length of the number in parameter.
 * 
 * @param n 
 * @return int 
 */
static int	ft_nblen(int n)
{
	int	nblen;

	if (n == 0)
		return ((int)2);
	nblen = 0;
	if (n < 0)
		nblen = 1;
	while (n < 0 || n > 0)
	{
		n = n / 10;
		nblen++;
	}
	return (nblen + 1);
}

/**
 * @brief Return a malloc'ed string representing the integer sent in parameter.
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itoa(int n)
{
	char			*result;
	int				nblen;
	unsigned int	nbr;

	nblen = ft_nblen(n);
	nbr = n;
	if (n < 0)
		nbr = -n;
	result = (char *)ft_calloc(nblen, sizeof(char));
	if (!result)
		return (NULL);
	result[--nblen] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (nblen >= 1)
	{
		result[--nblen] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
