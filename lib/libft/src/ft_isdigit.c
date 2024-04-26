/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:32:50 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:20:06 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Return 1 if the character is 0-9, return 0 if not.
 * 
 * @param c 
 * @return int 
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
