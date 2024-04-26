/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:01:47 by recarlie          #+#    #+#             */
/*   Updated: 2022/05/31 14:42:14 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_exp(t_prog *prog)
{
	int	i;

	i = 0;
	if (prog->env_exp == NULL)
		return ;
	while (i < prog->env_exp->size)
	{
		if (prog->env_exp->key[i])
			free(prog->env_exp->key[i]);
		prog->env_exp->key[i] = NULL;
		if (prog->env_exp->value[i])
			free(prog->env_exp->value[i]);
		prog->env_exp->value[i] = NULL;
		i++;
	}
	free(prog->env_exp->key[i]);
	free(prog->env_exp->value[i]);
	free(prog->env_exp->key);
	prog->env_exp->key = NULL;
	free(prog->env_exp->value);
	prog->env_exp->value = NULL;
	free(prog->env_exp);
	prog->env_exp = NULL;
}
