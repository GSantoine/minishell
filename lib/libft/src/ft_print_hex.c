/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:17:04 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:38:40 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, c);
		ft_put_hex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				ft_putchar(n - 10 + 'a');
			if (c == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int n, const char c)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_put_hex(n, c);
	return (ft_hex_len(n));
}
