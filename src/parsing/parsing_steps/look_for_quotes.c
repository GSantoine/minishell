/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_expansions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:08:32 by agras             #+#    #+#             */
/*   Updated: 2022/08/05 22:08:48 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	identify_quotes(t_token *token, char *line)
{
	if (is_operator(token, line, "\'", OPEN_SQUOTES_FLTR) != -1)
		return (OPEN_SQUOTES_FLTR);
	if (is_operator(token, line, "\'", CLOSE_SQUOTES_FLTR) != -1)
		return (CLOSE_SQUOTES_FLTR);
	if (is_operator(token, line, "\"", OPEN_DQUOTES_FLTR) != -1)
		return (OPEN_DQUOTES_FLTR);
	if (is_operator(token, line, "\"", CLOSE_DQUOTES_FLTR) != -1)
		return (CLOSE_DQUOTES_FLTR);
	return (-1);
}

int	look_for_quotes(t_prog *prog, t_token *token)
{
	int	i;
	int	parsing_ret;
	int	parsing_index;

	i = 0;
	while (token->data[i])
	{
		parsing_index = identify_quotes(token, &token->data[i]);
		if (parsing_index != -1)
		{
			parsing_ret = (*prog->parsing_filters[parsing_index])(prog,
					token, &token->data[i]);
			if (parsing_ret != NOT_FOUND && parsing_ret != IGNORE)
				return (parsing_ret);
		}
		i++;
	}
	return (NOT_FOUND);
}
