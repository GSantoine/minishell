/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:13:54 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 17:22:24 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Return the index of the key in the env.
 * If the key doesn't exist, return -1.
 * 
 */
int	get_env_key_index(char *key, t_env *env)
{
	int	i;

	i = 0;
	if (!env || !key)
		return (-1);
	while (i < env->size)
	{
		if (!ft_strncmp(env->key[i], key, ft_strlen(key)))
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Return a pointer to the env variable with the key passed in parameter.
 * 
 * @param prog 
 * @param key 
 * @return char* 
 */
char	*get_env_value_by_key(t_prog *prog, char *key)
{
	int	i;

	i = 0;
	if (!prog->env || !prog->env->key)
		return (NULL);
	while (i < prog->env->size)
	{
		if (!ft_strncmp(prog->env->key[i], key, ft_strlen(key))
			&& prog->env->key[i][ft_strlen(key)] == '\0')
			return (prog->env->value[i]);
		i++;
	}
	return (NULL);
}

/**
 * @brief Print on STDOUT the environment variables. Warning : Those variables
 * includes the variables set by the user, even those that haven't values.
 * 
 * @param prog 
 */
void	print_env_exp(t_prog *prog, t_token *token)
{
	int	i;
	int	fd;

	i = 0;
	if (prog->index_max == 0)
		fd = prog->redir_fds[token->index][WEND];
	else
		fd = STDOUT_FILENO;
	if (!prog->env_exp || !prog->env_exp->key[0])
		return ((void)ft_putstr_fd("", fd));
	while (prog->env_exp->key[i])
	{
		ft_putstr_fd("export ", fd);
		ft_putstr_fd(prog->env_exp->key[i], fd);
		if (prog->env_exp->value[i] && prog->env_exp->value[i][0])
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(prog->env_exp->value[i], fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
		i++;
	}
	if (prog->index_max > 0)
		ft_exit(prog, NULL, "");
}

void	init_new_env_exp(t_prog *prog)
{
	t_env	*new_env;
	int		i;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
		return ;
	new_env->key = ft_calloc(prog->env_exp->size + 2, sizeof(char *));
	if (!new_env->key)
		return ;
	new_env->value = ft_calloc(prog->env_exp->size + 2, sizeof(char *));
	if (!new_env->value)
		return ;
	i = -1;
	while (++i < prog->env_exp->size)
	{
		new_env->key[i] = ft_strdup(prog->env_exp->key[i]);
		new_env->value[i] = ft_strdup(prog->env_exp->value[i]);
	}
	new_env->key[i + 1] = NULL;
	new_env->value[i + 1] = NULL;
	free_env_exp(prog);
	new_env->size = i;
	prog->env_exp = new_env;
}

/**
 * @brief Add a key and a value in the export environment.
 * 
 * @param prog 
 * @param val 
 */
void	add_in_env_exp(t_prog *prog, char *val)
{
	char	*value;
	char	*key;
	int		key_index;

	key = get_env_key_from_str(val);
	key_index = get_env_key_index(key, prog->env_exp);
	value = get_env_value_from_str(val);
	if (key_index != -1)
		edit_value_by_key(prog->env_exp, key, value);
	else
	{
		init_new_env_exp(prog);
		prog->env_exp->key[prog->env_exp->size] = key;
		prog->env_exp->value[prog->env_exp->size] = value;
		prog->env_exp->size += 1;
	}
}
