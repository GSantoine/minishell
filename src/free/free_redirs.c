/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:13:55 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:44:06 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirs(t_prog *prog)
{
	int	i;

	i = 0;
	if (!prog->redir_fds)
		return ;
	while (i <= prog->index_max)
	{
		if (prog->redir_fds[i][REND] > 1)
			close(prog->redir_fds[i][REND]);
		if (prog->redir_fds[i][WEND] > 1)
			close(prog->redir_fds[i][WEND]);
		free(prog->redir_fds[i]);
		i++;
	}
	free(prog->redir_fds);
	prog->redir_fds = NULL;
}
