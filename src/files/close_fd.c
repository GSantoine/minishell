/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:09:30 by recarlie          #+#    #+#             */
/*   Updated: 2022/05/16 10:02:32 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: Add `close_fd` to header.
/**
 * @brief Duplicate and close fd_in and/or fd_out.
 * 
 * @param fd_in 
 * @param fd_out 
 */
void	close_fd(int fd_in, int fd_out)
{
	if (fd_in)
	{
		dup2(fd_in, 0);
		close(fd_in);
	}
	if (fd_out != 1)
	{
		dup2(fd_out, 1);
		close(fd_out);
	}
}
