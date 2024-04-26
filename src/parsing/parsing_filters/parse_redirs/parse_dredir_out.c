/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dredir_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:31:56 by agras             #+#    #+#             */
/*   Updated: 2022/08/07 14:30:35 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isolate_left(t_prog *prog, t_token *token, char *line)
{
	char	*data;

	if (line != token->data)
	{
		data = ft_strndup(token->data, line - token->data);
		if (token_add_left_child(&token, token_new(data, token->type,
					token->master_type, token->mask)) == FATAL_ERR)
			ft_exit(prog, NULL, "Memory allocation failded\n");
		return (parse_cmd(prog, token->left_child));
	}
	if (token->type == OUTFILE || token->type == INFILE
		|| token->type == APPEND_OUTFILE || token->type == HEREDOC)
	{
		ft_putstr_fd("Syntax error\n", STDERR_FILENO);
		return (FATAL_ERR);
	}
	return (OK);
}

static int	isolate_right(t_prog *prog, t_token *token, char *line)
{
	char	*data;

	if (*line != '\0')
	{
		data = ft_strndup(line, ft_strlen(line));
		if (token_add_right_child(&token, token_new(data, APPEND_OUTFILE,
					APPEND_OUTFILE, token->mask)) == FATAL_ERR)
			ft_exit(prog, NULL, "Memory allocation failded\n");
		return (parse_cmd(prog, token->right_child));
	}
	ft_putstr_fd("Syntax error\n", STDERR_FILENO);
	return (FATAL_ERR);
}

int	parse_dredir_out(t_prog *prog, t_token *token, char *line)
{
	if (isolate_left(prog, token, line) == FATAL_ERR)
		return (FATAL_ERR);
	line += 2;
	if (isolate_right(prog, token, line) == FATAL_ERR)
		return (FATAL_ERR);
	token->type = DREDIR_OUT;
	return (OK);
}
