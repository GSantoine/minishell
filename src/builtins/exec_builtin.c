/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:11:43 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Returns 0 if the command isn't builtin, 1 if it is.
 * 
 * @param cmd 
 * @return int 
 */
int	is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "exit", 4) == 0 && ft_strlen(cmd) == 4)
		return (1);
	if (ft_strncmp(cmd, "pwd", 3) == 0 && ft_strlen(cmd) == 3)
		return (1);
	if (ft_strncmp(cmd, "echo", 4) == 0 && ft_strlen(cmd) == 4)
		return (1);
	if (ft_strncmp(cmd, "cd", 2) == 0 && ft_strlen(cmd) == 2)
		return (1);
	if (ft_strncmp(cmd, "env", 3) == 0 && ft_strlen(cmd) == 3)
		return (1);
	if (ft_strncmp(cmd, "export", 6) == 0 && ft_strlen(cmd) == 6)
		return (1);
	if (ft_strncmp(cmd, "unset", 5) == 0 && ft_strlen(cmd) == 5)
		return (1);
	return (0);
}

/**
 * @brief If detected command is supposed to be built-in, execute it.
 * 
 * @param prog 
 */
void	exec_builtin(t_prog *prog, char **args, t_token *token)
{
	if (ft_strncmp(args[0], "exit", 4) == 0)
		ft_exit(prog, args, NULL);
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
		ft_pwd(prog, token);
	else if (ft_strncmp(args[0], "echo", 4) == 0)
		ft_echo(prog, args, token);
	else if (ft_strncmp(args[0], "cd", 2) == 0)
		g_return_value = ft_cd(prog, args, token);
	else if (ft_strncmp(args[0], "env", 3) == 0)
		ft_env(prog, token);
	else if (ft_strncmp(args[0], "export", 6) == 0)
		ft_export(prog, args, 0, token);
	else if (ft_strncmp(args[0], "unset", 5) == 0)
		ft_unset(prog, args);
	free_redirs(prog);
	free(args);
}
