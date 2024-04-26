/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:31:14 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:33:30 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_fd_index_lower(t_prog *prog, int index)
{
	if (prog->pipes[index - 1][REND] > 0)
		close(prog->pipes[index - 1][REND]);
	if (prog->pipes[index][WEND] > 1)
		close(prog->pipes[index][WEND]);
	if (prog->redir_fds[index][WEND] > 1)
		close(prog->redir_fds[index][WEND]);
	if (prog->redir_fds[index - 1][REND] > 1)
		close(prog->redir_fds[index - 1][REND]);
}

/**
 * @brief Close mandatory file descriptors in the parent process.
 * 
 * @param prog 
 * @param index 
 */
void	close_fds_parent(t_prog *prog, int index)
{
	if (index == 0)
	{
		if (prog->index_max > 0 && prog->pipes[index][WEND] > 1)
			close(prog->pipes[index][WEND]);
		if (prog->redir_count > 0 && prog->redir_fds[index][WEND] > 1)
			close(prog->redir_fds[index][WEND]);
		if (prog->redir_count > 0 && prog->redir_fds[index][REND] > 0)
			close(prog->redir_fds[index][REND]);
	}
	else if (index < prog->index_max)
		close_fd_index_lower(prog, index);
	else if (index == prog->index_max && index > 0)
	{
		if (prog->pipes[index - 1][REND] > 0)
			close(prog->pipes[index - 1][REND]);
		if (prog->redir_count > 0 && prog->redir_fds[index - 1][WEND] > 1)
			close(prog->redir_fds[index - 1][WEND]);
		if (prog->redir_count > 1 && prog->redir_fds[index - 1][REND] > 0)
			close(prog->redir_fds[index - 1][REND]);
	}
}

void	close_lower_redir(t_prog *prog, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		close_fds_parent(prog, i);
		if (prog->redir_fds[i][WEND] > 1)
			close(prog->redir_fds[i][WEND]);
		if (prog->redir_fds[i][REND] > 0)
			close(prog->redir_fds[i][REND]);
		i++;
	}
}

/**
 * @brief Close every additional file descriptors of the child process.
 * 
 * @param prog 
 * @param index 
 */
void	close_further_fds(t_prog *prog, int index)
{
	int	i;

	i = index;
	close_lower_redir(prog, index);
	while (i < prog->index_max)
	{
		if (prog->pipes[i][REND] > 0)
			close(prog->pipes[i][REND]);
		if (prog->pipes[i][WEND] > 1)
			close(prog->pipes[i][WEND]);
		i++;
	}
	i = 0;
	while (i <= prog->index_max)
	{
		if (prog->redir_fds[i][REND] > 1)
			close(prog->redir_fds[i][REND]);
		if (prog->redir_fds[i][WEND] > 1)
			close(prog->redir_fds[i][WEND]);
		i++;
	}
}
