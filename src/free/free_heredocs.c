/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:49:08 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:35:53 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	kill_heredocs(t_prog *prog)
{
	int	i;

	i = 0;
	if (!prog->heredoc_names)
		return ;
	while (i <= prog->index_max)
	{
		free(prog->heredoc_names[i]);
		prog->heredoc_names[i] = NULL;
		i++;
	}
}

void	free_heredocs(t_prog *prog)
{
	int	i;

	i = 0;
	if (!prog->heredoc_names)
		return ;
	while (i <= prog->index_max)
	{
		if (prog->heredoc_names[i])
			if (unlink(prog->heredoc_names[i]) == -1)
				break ;
		i++;
	}
	kill_heredocs(prog);
	free(prog->heredoc_names);
	prog->heredoc_names = NULL;
}
