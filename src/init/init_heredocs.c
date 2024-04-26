/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:18:53 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/12 18:53:17 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_heredocs(t_prog *prog)
{
	prog->heredoc_names = ft_calloc(prog->index_max + 1, sizeof(char *));
	if (prog->heredoc_names == NULL)
		ft_exit(prog, NULL, "Error: malloc failed\n");
}
