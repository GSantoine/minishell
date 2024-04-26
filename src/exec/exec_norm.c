/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:26:37 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 17:20:13 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_index_zero(t_prog *prog, t_token *tokens)
{
	if (prog->index_max > 0 && prog->redir_fds[tokens->index][WEND] == 1)
		dup2(prog->pipes[tokens->index][WEND], STDOUT_FILENO);
	if (prog->redir_fds[tokens->index][WEND] > 1)
	{
		if (is_builtin(tokens->data) && prog->index_max == 0)
			return ;
		dup2(prog->redir_fds[tokens->index][WEND], STDOUT_FILENO);
		close(prog->redir_fds[tokens->index][WEND]);
	}
	if (prog->redir_fds[tokens->index][REND] > 0)
	{
		if (is_builtin(tokens->data) && prog->index_max == 0)
			return ;
		dup2(prog->redir_fds[tokens->index][REND], STDIN_FILENO);
		close(prog->redir_fds[tokens->index][REND]);
	}
	if (prog->index_max > 0)
	{
		close(prog->pipes[tokens->index][WEND]);
		close(prog->pipes[tokens->index][REND]);
	}
}

void	exec_index_not_max(t_prog *prog, t_token *tokens)
{
	if (prog->redir_fds[tokens->index][WEND] > 1)
	{
		dup2(prog->redir_fds[tokens->index][WEND], STDOUT_FILENO);
		close(prog->redir_fds[tokens->index][WEND]);
	}
	else
		dup2(prog->pipes[tokens->index][WEND], STDOUT_FILENO);
	if (prog->redir_fds[tokens->index][REND] > 0)
	{
		dup2(prog->redir_fds[tokens->index][REND], STDIN_FILENO);
		close(prog->redir_fds[tokens->index][REND]);
	}
	else
		dup2(prog->pipes[tokens->index - 1][REND], STDIN_FILENO);
	close(prog->pipes[tokens->index][WEND]);
	close(prog->pipes[tokens->index - 1][REND]);
	close(prog->pipes[tokens->index][REND]);
}

void	exec_index_max(t_prog *prog, t_token *tokens)
{
	if (prog->redir_fds[tokens->index][WEND] > 1)
	{
		dup2(prog->redir_fds[tokens->index][WEND], STDOUT_FILENO);
		close(prog->redir_fds[tokens->index][WEND]);
	}
	if (prog->redir_fds[tokens->index][REND] > 0)
	{
		dup2(prog->redir_fds[tokens->index][REND], STDIN_FILENO);
		close(prog->redir_fds[tokens->index][REND]);
	}
	else
		dup2(prog->pipes[tokens->index - 1][REND], STDIN_FILENO);
	close(prog->pipes[tokens->index - 1][REND]);
}

void	exec_not_builtin(t_prog *prog, char **argv)
{
	char	*path;
	char	**env;
	char	*err_msg;

	err_msg = NULL;
	if (!argv)
		return ;
	path = get_cmd_path(prog, argv[0]);
	if (!path)
		path = ft_strdup(argv[0]);
	env = get_env(prog, prog->env);
	execve(path, argv, env);
	err_msg = ft_strjoin_new("minishell: ", path, 0, 1);
	err_msg = ft_strjoin_new(err_msg, ": command not found\n", 1, 0);
	ft_free_char_array(env, 1);
	ft_custom_exit(prog, errno + 125, err_msg, 1);
}
