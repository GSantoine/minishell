/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:30:05 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 17:23:22 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset_env_exp_norm(t_prog *prog, int j)
{
	while (j < prog->env_exp->size - 1)
	{
		prog->env_exp->key[j] = prog->env_exp->key[j + 1];
		prog->env_exp->value[j] = prog->env_exp->value[j + 1];
		j++;
	}
	prog->env_exp->key[j] = NULL;
	prog->env_exp->value[j] = NULL;
	prog->env_exp->size -= 1;
}

void	ft_unset_env_exp(t_prog *prog, char **args)
{
	int		i;
	int		j;

	i = 0;
	while (args[++i])
	{
		j = -1;
		while (++j < prog->env_exp->size)
		{
			if (!ft_strncmp(prog->env_exp->key[j], args[i], ft_strlen(args[i]))
				&& prog->env_exp->key[j][ft_strlen(args[i])] == '\0')
			{
				free(prog->env_exp->key[j]);
				free(prog->env_exp->value[j]);
				ft_unset_env_exp_norm(prog, j);
			}
		}
	}
	if (prog->index_max > 0)
	{
		ft_free_char_array(args, 1);
		exit(1);
	}
}

void	ft_unset_norm(t_prog *prog, int j)
{
	while (j < prog->env->size - 1)
	{
		prog->env->key[j] = prog->env->key[j + 1];
		prog->env->value[j] = prog->env->value[j + 1];
		j++;
	}
	prog->env->key[j] = NULL;
	prog->env->value[j] = NULL;
	prog->env->size -= 1;
}

/**
 * @brief Remove a variable from the environment.
 * 
 * @param prog 
 * @param args 
 */
void	ft_unset(t_prog *prog, char **args)
{
	int		i;
	int		j;

	i = 0;
	ft_unset_env_exp(prog, args);
	while (args[++i])
	{
		j = 0;
		while (j < prog->env->size)
		{
			if (!ft_strncmp(prog->env->key[j], args[i], ft_strlen(args[i]))
				&& prog->env->key[j][ft_strlen(args[i])] == '\0')
			{
				free(prog->env->key[j]);
				free(prog->env->value[j]);
				ft_unset_norm(prog, j);
			}
			j++;
		}
	}
	if (prog->index_max > 0)
	{
		ft_free_char_array(args, 1);
		exit(1);
	}
}
