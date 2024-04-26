/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_type_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:37:37 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:33:36 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief If the token is type PIPE, then create a new pipe and store it in the
 * program structure.
 * 
 * @param prog 
 * @param token 
 */
void	check_pipe(t_prog *prog, t_token *token)
{
	if (token->type == PIPE)
	{
		if (prog->index_max == 0)
			return ;
		if (pipe(prog->pipes[token->index]) == -1)
			ft_exit(prog, NULL, "minishell: too much fds\n");
		prog->pipe_count++;
	}
}

/**
 * @brief If the token is type *REDIR_* then execute the redirection.
 * Malloc prog->redir_fds and store the fds in it.
 * 
 * @param prog 
 * @param token 
 */
void	check_redir(t_prog *prog, t_token *token)
{
	if (token->type == INFILE)
		redir_in(prog, token);
	else if (token->type == OUTFILE)
		redir_out(prog, token);
	else if (token->type == APPEND_OUTFILE)
		redir_out_append(prog, token);
}

/**
 * @brief If the token is type CMD, then execute the command in a child process.
 * 
 * @param prog 
 * @param token 
 */
void	check_cmd(t_prog *prog, t_token *token)
{
	if (token->type == CMD && token->doable == 1)
		exec_command_child_fork(prog, token);
}

void	count_redir(t_prog *prog, t_token *token)
{
	if (!prog->redir_count)
		prog->redir_count = 0;
	if (token->type == REDIR_IN)
		prog->redir_count += 1;
	else if (token->type == REDIR_OUT)
		prog->redir_count += 1;
	else if (token->type == DREDIR_OUT)
		prog->redir_count += 1;
}

/**
 * @brief Check the token type and execute the corresponding function.
 * 
 * @param prog 
 * @param token 
 * @param index 
 */
void	check_token(t_prog *prog, t_token *token, int index)
{
	if (!token)
		return ;
	if (index == 0)
		count_redir(prog, token);
	else if (index == 1)
		check_heredoc(prog, token);
	else if (index == 2)
		check_pipe(prog, token);
	else if (index == 3)
		check_redir(prog, token);
	else if (index == 4)
		check_cmd(prog, token);
}
