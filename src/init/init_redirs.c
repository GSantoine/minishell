/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:17:07 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:36:15 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_redirs(t_prog *prog, int index_max)
{
	int	i;

	i = 0;
	prog->redir_fds = (int **)malloc(sizeof(int *) * (index_max + 1));
	while (i <= index_max)
	{
		prog->redir_fds[i] = (int *)malloc(sizeof(int) * 2);
		prog->redir_fds[i][REND] = 0;
		prog->redir_fds[i][WEND] = 1;
		i++;
	}
}
