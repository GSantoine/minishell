/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:02:44 by agras             #+#    #+#             */
/*   Updated: 2022/08/07 14:46:38 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*trim_begin_spaces(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (ft_strdup(line + i));
}

void	trim_end_spaces(char *line)
{
	int	len;

	if (!line)
		return ;
	len = ft_strlen(line) - 1;
	while (len >= 0)
	{
		if (line[len] != ' ')
		{
			line[len + 1] = '\0';
			break ;
		}
		len--;
	}
}

char	*trim_spaces(char *data)
{
	char	*dup;

	dup = trim_begin_spaces(data);
	if (data)
		free(data);
	return (dup);
}
