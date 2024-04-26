/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:48:47 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:36:13 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Initialize every pipelines. Those values will be modified by
 * further redirections.
 * 
 * @param prog 
 * @param index_max 
 */
void	init_pipes(t_prog *prog, int index_max)
{
	int	i;

	i = 0;
	if (prog->index_max == 0)
		return ;
	prog->pipes = malloc(sizeof(int *) * (index_max));
	if (!prog->pipes)
		printf("init_pipes: malloc failed\n");
	while (i < index_max)
	{
		prog->pipes[i] = malloc(sizeof(int) * 2);
		if (!prog->pipes[i])
			printf("init_pipes[%d]: malloc failed\n", i);
		prog->pipes[i][REND] = 0;
		prog->pipes[i][WEND] = 1;
		i++;
	}
}
