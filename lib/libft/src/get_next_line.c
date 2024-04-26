/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:17:59 by recarlie          #+#    #+#             */
/*   Updated: 2022/04/04 15:09:45 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_leftovers(int fd, char *leftover)
{
	char	*buffer;
	int		rode_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rode_bytes = 1;
	while (!ft_strchr_gnl(leftover, '\n') && rode_bytes != 0)
	{
		rode_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rode_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rode_bytes] = '\0';
		leftover = ft_strjoin_gnl(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

/**
 * @brief Get the next line object from 'fd' file descriptor.
 * 
 * @param fd 
 * @return char* 
 */
char	*get_next_line(int fd)
{
	char		*result;
	static char	*leftover[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftover[fd] = get_leftovers(fd, leftover[fd]);
	if (!leftover[fd])
		return (NULL);
	result = get_line(leftover[fd]);
	leftover[fd] = getrid_old_line(leftover[fd]);
	return (result);
}
