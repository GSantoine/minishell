/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:17:35 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_new_env(t_prog *prog)
{
	t_env	*new_env;
	int		i;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!new_env)
		return ;
	new_env->key = ft_calloc(prog->env->size + 1, sizeof(char *));
	if (!new_env->key)
		return ;
	new_env->value = ft_calloc(prog->env->size + 1, sizeof(char *));
	if (!new_env->value)
		return ;
	i = -1;
	while (++i < prog->env->size)
	{
		new_env->key[i] = ft_strdup(prog->env->key[i]);
		new_env->value[i] = ft_strdup(prog->env->value[i]);
	}
	free_env(prog);
	new_env->size = i + 1;
	prog->env = new_env;
}

void	ft_export_norm(t_prog *prog, char **args, char *key, int i)
{
	if (args[i][0] == '=' || (!ft_isalpha(key[0]) && key[0] != '_') ||
		!ft_isalphanum_str(key))
	{
		ft_putendl_fd("export: '=': not a valid identifier", 2);
		g_return_value += i;
	}
	else if (args[i][0] == '\0')
		ft_putendl_fd("export: missing name", 2);
	else
		ft_setenv(prog, args);
}
