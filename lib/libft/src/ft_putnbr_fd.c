/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:52:44 by recarlie          #+#    #+#             */
/*   Updated: 2022/05/16 12:46:23 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	buffer[12];
	char	sign;
	int		i;

	ft_bzero(buffer, 12);
	i = 11;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	sign = 0;
	if (n < 0)
	{
		sign = '-';
		n = -n;
	}
	while (n > 9 && --i >= 0)
	{
		buffer[i] = (n % 10) + '0';
		n = n / 10;
	}
	buffer[i - 1] = n + '0';
	buffer[i - 2] = sign;
	i = 0;
	while (*(buffer + i) == 0 && i < 11)
		i++;
	return (ft_putstr_fd(buffer + i, fd));
}
