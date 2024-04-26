/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:47:44 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/23 16:43:39 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int n)
{
	int		result;
	char	*nbr;

	result = 0;
	nbr = ft_itoa(n);
	result = ft_print_str(nbr);
	free(nbr);
	return (result);
}
