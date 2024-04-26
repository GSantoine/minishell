/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:58:22 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/23 16:43:39 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len(unsigned int n)
{
	int	nbr_len;

	nbr_len = 0;
	while (n != 0)
	{
		nbr_len++;
		n /= 10;
	}
	return (nbr_len);
}

char	*ft_uitoa(unsigned int n)
{
	int		nbr_len;
	char	*nbr;

	nbr_len = ft_nbr_len(n);
	nbr = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!nbr)
		return (NULL);
	nbr[nbr_len] = '\0';
	while (n != 0)
	{
		nbr[nbr_len - 1] = n % 10 + 48;
		n /= 10;
		nbr_len--;
	}
	return (nbr);
}

int	ft_print_uint(unsigned int n)
{
	int		result;
	char	*nbr;

	if (n == 0)
	{
		result = 1;
		write(1, "0", 1);
	}
	else
	{
		nbr = ft_uitoa(n);
		result = ft_print_str(nbr);
		free(nbr);
	}
	return (result);
}
