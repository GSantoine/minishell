/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:00:24 by agras             #+#    #+#             */
/*   Updated: 2022/08/07 15:36:56 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_cmd(t_prog *prog, t_token *token)
{
	int	parsing_ret;

	if (token->mask[TRIM_SPACES_FLTR] == '1' && is_word(token->type))
		token->data = trim_spaces(token->data);
	if (!token->data)
		ft_exit(prog, NULL, "Memory allocation failded\n");
	parsing_ret = look_for_pipes_n_redirs(prog, token);
	if (parsing_ret != NOT_FOUND && parsing_ret != IGNORE)
		return (parsing_ret);
	parsing_ret = look_for_quotes(prog, token);
	if (parsing_ret != NOT_FOUND && parsing_ret != IGNORE)
		return (parsing_ret);
	parsing_ret = look_for_expansions(prog, token);
	if (parsing_ret != NOT_FOUND && parsing_ret != IGNORE)
		return (parsing_ret);
	if (!token)
		return (-1);
	return (OK);
}

int	execute_parsing_steps(t_prog *prog)
{
	expand_variables(prog, prog->tokens);
	specify_tokens(prog->tokens);
	if (remodel_parsing(prog->tokens) == FATAL_ERR)
		return (FATAL_ERR);
	set_index(prog, prog->tokens, 0);
	identify_args(prog->tokens, 0);
	return (0);
}

int	init_parser(t_prog *prog)
{
	if (ft_strlen(prog->line) == 0)
	{
		free(prog->line);
		return (FATAL_ERR);
	}
	prog->tokens = token_new(ft_strdup(prog->line), CMD, CMD, NULL);
	if (!prog->tokens)
		ft_exit(prog, NULL, "Memory allocation failded\n");
	init_parsing_hierarchy(prog);
	prog->index_max = 0;
	if (parse_cmd(prog, prog->tokens) == -1)
	{
		free(prog->line);
		prog->line = NULL;
		free_tokens(&prog->tokens);
		return (FATAL_ERR);
	}
	return (execute_parsing_steps(prog));
}

	// print_parsing(prog->tokens, "ROOT");