/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:29:54 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*malloc_env(int size)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->key = (char **)malloc(sizeof(char *) * (size + 1));
	if (!env->key)
		return (NULL);
	env->value = (char **)malloc(sizeof(char *) * (size + 1));
	if (!env->value)
		return (NULL);
	env->key[size] = NULL;
	env->value[size] = NULL;
	return (env);
}

/**
 * @brief Edit the value of a key in the env.
 * 
 * @param prog 
 * @param env 
 * @param key 
 * @param val 
 */
void	edit_value_by_key(t_env *env, char *key, char *new_val)
{
	int	i;

	i = -1;
	if (!new_val || !new_val[0])
		return (free(key));
	while (++i < env->size)
	{
		if (!ft_strncmp(env->key[i], key, ft_strlen(key))
			&& env->key[i][ft_strlen(key)] == '\0')
		{
			free(env->value[i]);
			env->value[i] = new_val;
			free(key);
			return ;
		}
	}
	if (key)
		free(key);
	if (new_val)
		free(new_val);
}

void	add_in_env(t_prog *prog, char *val)
{
	int		key_index;
	char	*key;
	char	*value;

	add_in_env_exp(prog, val);
	value = get_env_value_from_str(val);
	if (!value || value[0] == '\0')
		return (free(value));
	key = get_env_key_from_str(val);
	key_index = get_env_key_index(key, prog->env);
	if (key_index != -1)
		edit_value_by_key(prog->env, key, value);
	else
	{
		init_new_env(prog);
		prog->env->key[prog->env->size - 1] = key;
		prog->env->value[prog->env->size - 1] = value;
	}
}

void	ft_setenv(t_prog *prog, char **args)
{
	int		i;

	i = 0;
	while (args[++i])
		add_in_env(prog, args[i]);
}

void	ft_export(t_prog *prog, char **args, int free_args, t_token *token)
{
	int		i;
	char	*key;

	i = 0;
	key = NULL;
	if (!args[1])
		print_env_exp(prog, token);
	else
	{
		g_return_value = 0;
		while (args[++i])
		{
			free(key);
			key = get_env_key_from_str(args[i]);
			ft_export_norm(prog, args, key, i);
		}
		if (free_args)
			ft_free_char_array(args, 1);
		free(key);
	}
	if (prog->index_max > 0)
	{
		ft_free_char_array(args, 1);
		exit(g_return_value);
	}
}
