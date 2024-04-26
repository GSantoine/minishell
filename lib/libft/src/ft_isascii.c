/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:39:37 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:19:41 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Return 1 if the character in parameter is in ASCII' table.
 * 
 * @param c 
 * @return int 
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
