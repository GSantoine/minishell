/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:51:26 by recarlie          #+#    #+#             */
/*   Updated: 2022/05/30 12:11:09 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Open and read `filename` until the end.
 * 
 * @param filename 
 */
void	read_to_end(char *filename)
{
	char	*tmp;
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd <= -1)
		return ;
	tmp = NULL;
	tmp = ft_strdup("");
	while (ft_strncmp(tmp, filename, ft_strlen(filename))
		|| ft_strlen(tmp) != ft_strlen(filename))
	{
		free(tmp);
		tmp = readline("> ");
		if (ft_strlen(tmp) != ft_strlen(filename))
			ft_putendl_fd(tmp, fd);
	}
	close(fd);
	if (tmp != NULL)
		free(tmp);
}
