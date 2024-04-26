/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:40:45 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:39:14 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Print a character on standard output and returns 1.
 * 
 * @param c 
 * @return int 
 */
int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}
