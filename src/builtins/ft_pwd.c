/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:24:32 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_error(t_prog *prog)
{
	ft_putstr_fd("pwd: error retrieving current directory: ", 2);
	ft_putstr_fd("getcwd : cannot access parent directories: ", 2);
	ft_putendl_fd("No such file or directory", 2);
	g_return_value = 1;
	if (prog->index_max > 0)
		exit(g_return_value);
}

/**
 * @brief BUILTIN | pwd function prints on `STDOUT_FILENO` current
 * directory's name.
 * 
 * @param prog 
 */
void	ft_pwd(t_prog *prog, t_token *token)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (pwd_error(prog));
	if (prog->redir_fds[token->index][WEND] > 1 && prog->index_max == 0)
		ft_putendl_fd(cwd, prog->redir_fds[token->index][WEND]);
	else
		ft_putendl_fd(cwd, STDOUT_FILENO);
	if (cwd == NULL)
		g_return_value = 1;
	else
		g_return_value = 0;
	free(cwd);
	if (prog->index_max > 0)
		exit(g_return_value);
	return ;
}
