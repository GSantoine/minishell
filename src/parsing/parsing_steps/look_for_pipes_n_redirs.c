/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_pipes_n_redirs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:07:04 by agras             #+#    #+#             */
/*   Updated: 2022/08/06 20:16:12 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	identify_pipes_or_redirs(t_token *token, char *line)
{
	if (is_operator(token, line, "|", PIPE_FLTR) != -1)
		return (PIPE_FLTR);
	if (is_operator(token, line, "<<", DREDIR_IN_FLTR) != -1)
		return (DREDIR_IN_FLTR);
	if (is_operator(token, line, ">>", DREDIR_OUT_FLTR) != -1)
		return (DREDIR_OUT_FLTR);
	if (is_operator(token, line, "<", REDIR_IN_FLTR) != -1)
		return (REDIR_IN_FLTR);
	if (is_operator(token, line, ">", REDIR_OUT_FLTR) != -1)
		return (REDIR_OUT_FLTR);
	return (-1);
}

int	identify_priority_operators(t_token *token, char *line)
{
	int	parsing_index;

	parsing_index = identify_pipes_or_redirs(token, line);
	if (parsing_index != -1)
		return (parsing_index);
	if (is_operator(token, line, " ", SPACE_FLTR) != -1)
	{
		if (identify_pipes_or_redirs(token, line + 1) == -1)
			return (SPACE_FLTR);
	}
	return (-1);
}

int	check_for_pipes_or_redirs(t_prog *prog, t_token *token, int i)
{
	int	parsing_index;

	parsing_index = identify_priority_operators(token, &token->data[i]);
	if (parsing_index != -1)
		return ((*prog->parsing_filters[parsing_index])(prog,
			token, &token->data[i]));
	return (NOT_FOUND);
}

int	look_for_pipes_n_redirs(t_prog *prog, t_token *token)
{
	int	i;
	int	parsing_ret;
	int	quotes_ret;

	i = 0;
	quotes_ret = 0;
	while (token->data[i])
	{
		if (token->mask[IGNORE_QUOTES_FLTR] == '1')
			quotes_ret = ignore_quotes(token->data, &i);
		if (quotes_ret == -1)
		{
			ft_putstr_fd("Syntax error\n", STDERR_FILENO);
			return (FATAL_ERR);
		}
		else if (quotes_ret == 0)
		{
			parsing_ret = check_for_pipes_or_redirs(prog, token, i);
			if (parsing_ret != NOT_FOUND && parsing_ret != IGNORE)
				return (parsing_ret);
		}
		i++;
	}
	return (NOT_FOUND);
}
