/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:59:02 by agras             #+#    #+#             */
/*   Updated: 2022/08/07 14:23:39 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	go_to_next(char *line, char look_for)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == look_for)
			return (i);
		i++;
	}
	return (0);
}

int	delete_quote_and_search_next(char *line, char next_to_find)
{
	ft_strlcpy(line, line + 1, ft_strlen(line));
	return (remove_quotes(line, next_to_find));
}

int	remove_quotes(char *line, char to_find)
{
	if (!line)
		return (OK);
	while (*line)
	{
		if (to_find == '\0')
		{
			if (*line == '\"')
				return (delete_quote_and_search_next(line, '\"'));
			else if (*line == '\'')
				return (delete_quote_and_search_next(line, '\''));
		}
		else
			if (*line == to_find)
				return (delete_quote_and_search_next(line, '\0'));
		line++;
	}
	return (OK);
}
