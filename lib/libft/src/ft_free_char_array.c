/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:54:17 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/11 18:39:52 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Free whole content of a string array.
 * 
 * @param array Array to be free'd.
 * @param freecont 1 : free the array / 0 : doesn't
 */
void	ft_free_char_array(char **array, int freecont)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	if (!array[0])
	{
		free(array);
		array = NULL;
		return ;
	}
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	if (freecont && array)
	{
		free(array);
		array = NULL;
	}
}
