/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignore_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:31:58 by agras             #+#    #+#             */
/*   Updated: 2022/07/31 15:53:04 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ignore_until(char *line, char until_this, int *i)
{
	*i += 1;
	while (line[*i])
	{
		if (line[*i] == until_this)
			return (1);
		*i += 1;
	}
	return (-1);
}

int	ignore_quotes(char *line, int *i)
{
	if (line[*i] == '\"')
	{
		return (ignore_until(line, '\"', i));
	}
	else if (line[*i] == '\'')
		return (ignore_until(line, '\'', i));
	return (0);
}
