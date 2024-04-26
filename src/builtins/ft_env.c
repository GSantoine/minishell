/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:29:30 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/12 16:53:20 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Return the future amount of values registered in future env.
 * (Used by ft_export)
 * 
 * @param prog 
 * @param args 
 * @return int 
 */
int	get_new_env_size(t_prog *prog, char **args)
{
	int		i;
	int		j;
	char	*key;
	char	*pos;

	i = prog->env->size;
	j = 0;
	key = NULL;
	while (args[j])
	{
		key = get_env_key_from_str(args[j]);
		pos = ft_strchr(args[j], '=');
		if (pos && pos[1] && get_env_key_index(key, prog->env) == -1)
			i++;
		if (key)
			free(key);
		j++;
	}
	return (i);
}

/**
 * @brief Return the amount of values registered in current environment.
 * (Used by ft_export)
 *
 * @param prog 
 * @return int 
 */
int	get_env_size(t_prog *prog)
{
	int		i;

	i = 0;
	if (!prog->env)
		return (0);
	while (i < prog->env->size && prog->env->key[i])
		i++;
	return (i);
}

int	get_env_exp_size(t_prog *prog)
{
	int	i;

	i = 0;
	while (prog->env_exp->key[i])
		i++;
	return (i);
}

/**
 * @brief Duplicate in the array the values registered in current env.
 * (Used by ft_export)
 * 
 * @param prog 
 * @param new_env 
 */
void	duplicate_env(t_prog *prog, t_env *new_env)
{
	int		i;

	i = -1;
	while (++i < prog->env->size)
	{
		new_env->key[i] = ft_strdup(prog->env->key[i]);
		new_env->value[i] = ft_strdup(prog->env->value[i]);
	}
}

void	ft_env(t_prog *prog, t_token *token)
{
	int	i;
	int	fd;

	i = 0;
	fd = STDOUT_FILENO;
	if (prog->index_max > 0 && prog->redir_fds[token->index][WEND] > 1)
		fd = prog->redir_fds[token->index][WEND];
	if (!prog->env->key || !prog->env->key[0])
		return ((void)ft_putstr_fd("", fd));
	while (i < prog->env->size)
	{
		ft_putstr_fd(prog->env->key[i], fd);
		ft_putchar_fd('=', fd);
		ft_putstr_fd(prog->env->value[i], fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
	if (prog->index_max > 0)
	{
		free_prog(prog);
		exit(1);
	}
}
