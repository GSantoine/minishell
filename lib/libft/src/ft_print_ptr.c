/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:50:46 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/23 16:43:39 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(uintptr_t n)
{
	int	result;

	result = 0;
	while (n != 0)
	{
		result++;
		n /= 16;
	}
	return (result);
}

void	ft_put_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	result;

	if (ptr == 0)
	{
		result = 3;
		write(1, "0x0", 3);
	}
	else
	{
		write(1, "0x", 2);
		ft_put_ptr(ptr);
		result = ft_ptr_len(ptr) + 2;
	}
	return (result);
}
