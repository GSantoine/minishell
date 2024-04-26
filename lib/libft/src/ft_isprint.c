/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:40:40 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:20:21 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Return 1 if the character is printable.
 * 
 * @param c 
 * @return int 
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
