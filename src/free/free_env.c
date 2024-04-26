/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:02:50 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:43:47 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_prog *prog)
{
	int	i;

	i = 0;
	if (prog->env == NULL)
		return ;
	while (i < prog->env->size)
	{
		if (prog->env->key[i])
			free(prog->env->key[i]);
		prog->env->key[i] = NULL;
		if (prog->env->value[i])
			free(prog->env->value[i]);
		prog->env->value[i] = NULL;
		i++;
	}
	free(prog->env->key);
	prog->env->key = NULL;
	free(prog->env->value);
	prog->env->value = NULL;
	free(prog->env);
	prog->env = NULL;
}
