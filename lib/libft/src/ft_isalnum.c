/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:17:26 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:18:44 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Return 1 if the caracter in argument is 0-9 a-Z, return 0 if not.
 * 
 * @param c 
 * @return int 
 */
int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
