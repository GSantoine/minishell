/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:59:24 by recarlie          #+#    #+#             */
/*   Updated: 2022/05/31 14:42:17 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_path(t_prog *prog)
{
	int	i;

	i = 0;
	if (prog->path == NULL)
		return ;
	while (prog->path[i])
	{
		free(prog->path[i]);
		prog->path[i] = NULL;
		i++;
	}
	free(prog->path);
	prog->path = NULL;
}
