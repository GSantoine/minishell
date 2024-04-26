/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:47:04 by agras             #+#    #+#             */
/*   Updated: 2022/08/06 20:04:37 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_for_metachar(char *line, char *metachar)
{
	int	i;

	i = 0;
	while (metachar[i])
	{
		if (!line[i] || metachar[i] != line[i])
			return (-1);
		i++;
	}
	return (i);
}

int	is_operator(t_token *token, char *line, char *metachar, int index)
{
	int	search_return;

	search_return = search_for_metachar(line, metachar);
	if (search_return != -1)
	{
		if (token->mask[index] == '1')
			return (search_return);
	}
	return (-1);
}

char	*ft_strndup(char *str, int len)
{
	char	*dup;
	int		i;

	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	count_spaces_head(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	return (i);
}
