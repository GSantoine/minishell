/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:24:47 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Search in `prog->env` for the key `var` and returns its value.
 * If no key found, returns NULL.
 * 
 * @param prog 
 * @param var 
 * @return char* 
 */
char	*ft_getenv(t_prog *prog, char *var)
{
	int	i;

	i = 0;
	while (prog->env->key[i])
	{
		if (ft_strncmp(prog->env->key[i], var, ft_strlen(var)) == 0
			&& prog->env->key[i][4] == '=')
			return (prog->env->value[i]);
		i++;
	}
	return (NULL);
}

void	print_nfd_cd(char *path)
{
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	g_return_value = 1;
}

void	exception_cd(t_prog *prog, t_token *token)
{
	char	**exception;

	exception = ft_calloc(3, sizeof(char *));
	exception[0] = ft_strdup("export");
	exception[1] = ft_strjoin("OLDPWD=", get_env_value_by_key(prog, "PWD"));
	ft_export(prog, exception, 0, token);
	ft_free_char_array(exception, 1);
	g_return_value = 0;
}

int	ft_cd(t_prog *prog, char **args, t_token *token)
{
	char	*path;

	path = args[1];
	if (args[1])
	{
		if (args[2])
			return (ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO));
	}
	else
		path = get_env_value_by_key(prog, "HOME");
	if (!path)
		return (1 + ft_putstr_fd("cd: no home directory\n", STDERR_FILENO));
	g_return_value = chdir(path);
	if (g_return_value == -1)
		print_nfd_cd(path);
	else
		exception_cd(prog, token);
	if (prog->index_max > 0)
	{
		free_prog(prog);
		exit(g_return_value);
	}
	return (g_return_value);
}
