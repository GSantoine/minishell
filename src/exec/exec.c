/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:52:33 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env(t_prog *prog, t_env *env)
{
	char	**env_cpy;
	char	*tmp;
	int		i;

	i = get_env_size(prog);
	env_cpy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!env_cpy)
		return (NULL);
	i = 0;
	while (i < prog->env->size)
	{
		tmp = ft_strjoin(env->key[i], "=");
		env_cpy[i] = ft_strjoin(tmp, env->value[i]);
		free(tmp);
		i++;
	}
	env_cpy[i] = NULL;
	return (env_cpy);
}

/**
 * @brief Execute the command in a child process. The function will get the
 * argv from the tokens and execute the command. If the command is not found, the
 * function will print an error message.
 * 
 * @param prog 
 */
int	exec_command_child(t_prog *prog, t_token *tokens)
{
	char	**argv;

	argv = NULL;
	if (tokens->index == 0)
		exec_index_zero(prog, tokens);
	else if (tokens->index != prog->index_max)
		exec_index_not_max(prog, tokens);
	else
		exec_index_max(prog, tokens);
	if (!(is_builtin(tokens->data)) || prog->index_max > 0)
		close_further_fds(prog, tokens->index);
	argv = get_argv_from_tokens(prog->tokens, tokens->index);
	if (is_builtin(tokens->data))
		exec_builtin(prog, argv, tokens);
	else
		exec_not_builtin(prog, argv);
	return (g_return_value);
}

/**
 * @brief Open a new process and execute the command.
 * 
 * @param prog 
 * @param tokens 
 * @param env 
 */
void	exec_command_child_fork(t_prog *prog, t_token *tokens)
{
	if (is_builtin(tokens->data) && prog->index_max == 0)
		exec_command_child(prog, tokens);
	else
	{
		prog->pids[tokens->index] = fork();
		prog->pid = prog->pids[tokens->index];
		if (prog->pids[tokens->index] == 0)
		{
			signal(SIGQUIT, backslash);
			exec_command_child(prog, tokens);
		}
		else
			close_fds_parent(prog, tokens->index);
	}
}

/**
 * @brief Recursively check the kind of token.
 * 
 * @param prog 
 * @param token 
 * @param index 
 */
void	recursive_check(t_prog *prog, t_token *token, int index)
{
	if (!token)
		return ;
	check_token(prog, token, index);
	if (token->left_child)
		recursive_check(prog, token->left_child, index);
	if (token->right_child)
		recursive_check(prog, token->right_child, index);
}

/**
 * @brief Check the kind of token and recursively check the next token.
 * The loop is called 3 times and follow this order:
 * 1. Check if the token is a pipe.
 * 2. Check if the token is a redirection.
 * 3. Check if the token is a command.
 * 
 * @param prog 
 * @param env 
 * @param token 
 * @return int 
 */
int	exec_prog(t_prog *prog, t_token *token)
{
	int	i;

	i = 0;
	if (!token)
		return (0);
	prog->redir_count = 0;
	while (i < 5)
	{
		if (i == 1)
		{
			init_redirs(prog, prog->index_max);
			init_heredocs(prog);
		}
		recursive_check(prog, token, i);
		i++;
	}
	return (1);
}
