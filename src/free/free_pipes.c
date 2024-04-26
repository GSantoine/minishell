/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:56:27 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:44:01 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipes(t_prog *prog)
{
	int	i;

	i = 0;
	if (!prog->pipes)
		return ;
	while (i < prog->pipe_count)
	{
		if (prog->pipes[i])
		{
			free(prog->pipes[i]);
			prog->pipes[i] = NULL;
		}
		i++;
	}
	if (prog->index_max > 0)
	{
		free(prog->pipes);
		prog->pipes = NULL;
	}
}
