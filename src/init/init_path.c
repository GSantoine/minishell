/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:48:09 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:36:08 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_path(t_prog *prog, char *path)
{
	char	**dump;

	if (!path)
	{
		ft_free_char_array(prog->path, 1);
		prog->path = NULL;
	}
	else
	{
		ft_free_char_array(prog->path, 1);
		prog->path = ft_split(path, ':');
		if (path)
		{
			dump = ft_split(prog->path[0], '=');
			free(prog->path[0]);
			prog->path[0] = ft_strdup(dump[1]);
			ft_free_char_array(dump, 1);
		}
	}
}

/**
 * @brief Initialize path environment variable.
 * 
 * @param prog 
 * @param env 
 */
void	init_path(t_prog *prog, char **env)
{
	static char	*path;
	int			i;
	char		**dump;

	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
		{
			path = ft_strdup(env[i]);
			break ;
		}
	}
	prog->path = ft_split(path, ':');
	if (path)
	{
		dump = ft_split(prog->path[0], '=');
		free(prog->path[0]);
		prog->path[0] = ft_strdup(dump[1]);
		ft_free_char_array(dump, 1);
	}
	if (path != NULL)
		free(path);
	prog->index_max = 0;
}
