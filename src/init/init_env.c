/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:49:24 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:36:05 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Return a malloc'd string containing the key value of the string
 * passed in parameter.
 * 
 * @param str 
 * @return char* 
 */
char	*get_env_key_from_str(char *str)
{
	char	*key;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	key = (char *)ft_calloc(i + 1, sizeof(char));
	if (!key)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	return (key);
}

/**
 * @brief Return a malloc'd string containing the value of the env variable.
 * 
 * @param str 
 * @return char* 
 */
char	*get_env_value_from_str(char *str)
{
	char	*value;
	char	*pos;
	int		i;
	int		size;

	i = 0;
	pos = ft_strchr(str, '=');
	if (!pos || !pos[1])
		return (ft_strdup(""));
	pos++;
	size = ft_strlen(pos) + 1;
	value = (char *)ft_calloc(size + 1, sizeof(char));
	if (!value)
		return (NULL);
	while (pos[i])
	{
		value[i] = pos[i];
		i++;
	}
	value[i] = '\0';
	return (value);
}

void	init_env_exp(t_prog *prog, int i, char **env)
{
	prog->env_exp = malloc(sizeof(t_env));
	if (!prog->env_exp)
		return ((void)ft_putstr_fd("Error: malloc failed init_env_exp1\n", 2));
	prog->env_exp->key = (char **)ft_calloc((i + 1), sizeof(char *));
	if (!prog->env_exp->key)
		return ((void)ft_putstr_fd("Error: init_env_exp malloc failed2.\n", 2));
	prog->env_exp->value = (char **)ft_calloc((i + 1), sizeof(char *));
	if (!prog->env_exp->value)
		return ((void)ft_putstr_fd("Error: init_env_exp malloc failed3.\n", 2));
	i = 0;
	while (env[i])
	{
		prog->env_exp->key[i] = get_env_key_from_str(env[i]);
		prog->env_exp->value[i] = get_env_value_from_str(env[i]);
		i++;
	}
	prog->env_exp->key[i] = NULL;
	prog->env_exp->value[i] = NULL;
	prog->env_exp->size = i;
}

void	init_env_norm(t_prog *prog, int i)
{
	prog->env->key[i] = NULL;
	prog->env->value[i] = NULL;
	prog->env->size = i;
}

/**
 * @brief Initialize environment variables for commands.
 * 
 * @param prog 
 * @param env 
 */
void	init_env(t_prog *prog, char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	prog->env = malloc(sizeof(t_env));
	if (!prog->env)
		return ((void)ft_putstr_fd("Error: malloc failed init_env1\n", 2));
	init_env_exp(prog, i, env);
	if (i > 0)
	{
		prog->env->key = (char **)ft_calloc(i + 1, sizeof(char *));
		if (!prog->env->key)
			return ((void)ft_putstr_fd("Error: init_env malloc failed.\n", 2));
		prog->env->value = (char **)ft_calloc(i + 1, sizeof(char *));
		if (!prog->env->value)
			return ((void)ft_putstr_fd("Error: init_env malloc failed.\n", 2));
		i = -1;
		while (env[++i] != NULL)
		{
			prog->env->key[i] = get_env_key_from_str(env[i]);
			prog->env->value[i] = get_env_value_from_str(env[i]);
		}
		init_env_norm(prog, i);
	}
}
