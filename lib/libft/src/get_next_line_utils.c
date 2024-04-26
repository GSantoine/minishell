/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:18:02 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/23 19:24:02 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*getrid_old_line(char *str)
{
	char	*new_leftovers;
	int		index;
	int		new_index;

	index = 0;
	new_index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	new_leftovers = malloc(sizeof(char) * (ft_strlen(str) - index + 1));
	if (!new_leftovers)
		return (NULL);
	index += 1;
	while (str[index])
		new_leftovers[new_index++] = str[index++];
	new_leftovers[new_index] = '\0';
	free(str);
	return (new_leftovers);
}

char	*get_line(char *str)
{
	char	*line;
	int		index;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	line = malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = 0;
	while (str[index] && str[index] != '\n')
	{
		line[index] = str[index];
		index++;
	}
	if (str[index] == '\n')
	{
		line[index] = str[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[++i] != '\0')
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
