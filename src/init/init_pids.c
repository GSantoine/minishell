/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:46:55 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:36:11 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Initialize the `pids` array of the `t_prog` structure.
 * The `pids` array is used to store the pids of the sub-processes.
 * 
 * @param prog 
 * @return int 
 */
int	init_pids(t_prog *prog)
{
	int	i;

	i = 0;
	prog->pids = NULL;
	prog->pids = malloc(sizeof(pid_t) * (prog->index_max + 1));
	if (!prog->pids)
	{
		printf("init_pids: malloc failed\n");
		return (-1);
	}
	if (i == 0)
		prog->pids[0] = 0;
	while (i <= prog->index_max - 1)
	{
		prog->pids[i] = 0;
		i++;
	}
	return (1);
}
