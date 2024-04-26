/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_closing_singlequote.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:47:17 by agras             #+#    #+#             */
/*   Updated: 2022/08/07 15:21:25 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isolate_left(t_prog *prog, t_token *token, char *line)
{
	char	*data;

	data = ft_strndup(token->data, line - token->data);
	if (token_add_left_child(&token, token_new(data, SQUOTES,
				token->master_type, token->mask)) == FATAL_ERR)
		ft_exit(prog, NULL, "Memory allocation failded\n");
	return (parse_cmd(prog, token->left_child));
}

static int	isolate_right(t_prog *prog, t_token *token, char *line)
{
	char	*data;

	if (*line != '\0')
	{
		data = ft_strndup(line, ft_strlen(line));
		if (token_add_right_child(&token, token_new(data, token->master_type,
					token->master_type, NULL)) == FATAL_ERR)
			ft_exit(prog, NULL, "Memory allocation failded\n");
		return (parse_cmd(prog, token->right_child));
	}
	return (OK);
}

int	parse_closing_single_quote(t_prog *prog, t_token *token, char *line)
{
	if (isolate_left(prog, token, line) == FATAL_ERR)
		return (FATAL_ERR);
	line += 1;
	if (isolate_right(prog, token, line) == FATAL_ERR)
		return (FATAL_ERR);
	token->type = CLOSE_SQUOTES;
	return (OK);
}
