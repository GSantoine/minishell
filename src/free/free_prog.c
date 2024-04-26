/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:59:07 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:44:03 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Free whole content of a int array.
 * 
 * @param array Array to be free'd.
 * @param freecont 1 : free the array / 0 : doesn't
 */
void	ft_free_int_array(t_prog *prog, int freecont)
{
	if (!prog->r_failed)
		return ;
	if (freecont && prog->r_failed)
	{
		free(prog->r_failed);
		prog->r_failed = NULL;
	}
}

void	free_line(t_prog *prog)
{
	if (prog->line)
		free(prog->line);
	prog->line = NULL;
}

// Function to free t_prog.
void	free_prog(t_prog *prog)
{
	if (prog == NULL)
		return ;
	free_redirs(prog);
	free_heredocs(prog);
	free_path(prog);
	free_env(prog);
	free_env_exp(prog);
	free_pids(prog);
	free_pipes(prog);
	ft_free_int_array(prog, 1);
	if (prog->line && prog->tokens)
		free_tokens(&prog->tokens);
	free_line(prog);
}
