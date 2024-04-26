/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:11 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/23 16:43:39 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	process_printf(const char c, va_list args)
{
	int	result;

	result = 0;
	if (c == 'c')
		result += ft_print_char(va_arg(args, int));
	else if (c == 's')
		result += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		result += ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		result += ft_print_int(va_arg(args, int));
	else if (c == 'u')
		result += ft_print_uint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		result += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		result += ft_print_char('%');
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;
	int		i;

	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result += process_printf(str[i + 1], args);
			i++;
		}
		else
			result += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}
