/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:41:31 by recarlie          #+#    #+#             */
/*   Updated: 2022/06/07 14:30:34 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write the string to the file descriptor.
 * 
 * @param str
 * @param fd
 * @return int
 */
int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen((const char *)s));
	return (1);
}
