/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pids.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:57:48 by recarlie          #+#    #+#             */
/*   Updated: 2022/05/31 14:42:19 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pids(t_prog *prog)
{
	if (prog->index_max > 0 || prog->line == NULL)
	{
		if (prog->pids)
		{
			free(prog->pids);
			prog->pids = NULL;
		}
	}
}
