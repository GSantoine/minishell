/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:37:25 by recarlie          #+#    #+#             */
/*   Updated: 2022/06/09 17:49:55 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief (Utils) Print every arguments of the command.
 * The first argument is the name of the command.
 * 
 * @param argv 
 */
void	print_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		write(2, argv[i], ft_strlen(argv[i]));
		i++;
	}
}

/**
 * @brief Get the cmd path from the env var PATH and check if it exists or not.
 * 
 * @param prog 
 * @param cmd 
 * @return char* 
 */
char	*get_cmd_path(t_prog *prog, char *cmd)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	path = NULL;
	if (!cmd || !prog->path || !(*cmd))
		return (NULL);
	if (cmd[0] == '/')
		return (NULL);
	ft_free_char_array(prog->path, 1);
	prog->path = ft_split(get_env_value_by_key(prog, "PATH"), ':');
	while (prog->path && prog->path[i] && cmd)
	{
		tmp = ft_strjoin(prog->path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

/**
 * @brief Count and return the number of arguments of the current command.
 * 
 * @param token 
 * @return int 
 */
int	count_args(t_token *token, int index)
{
	int	count;

	count = 0;
	if (!token)
		return (0);
	if (token->type == ARG && token->index == index)
		count++;
	if (token->left_child)
		count += count_args(token->left_child, index);
	if (token->right_child)
		count += count_args(token->right_child, index);
	return (count);
}

void	get_childs(t_token *tokens, char **argv, int *i, int index)
{
	if (tokens->type == CMD && tokens->index == index)
		argv[0] = tokens->data;
	if (tokens->index == index && tokens->type == ARG)
	{
		argv[*i] = tokens->data;
		*i += 1;
	}
	if (tokens->left_child)
		get_childs(tokens->left_child, argv, i, index);
	if (tokens->right_child)
		get_childs(tokens->right_child, argv, i, index);
}

/**
 * @brief Get the argv from tokens object. The first element of argv is the
 * value of the first token. The function will recursively get the rest of the
 * argv, in every childs and sub-childs of the first token. Since every value is
 * already malloced, the function will just concatenate the value of the token
 * in argv.
 * 
 * @param tokens 
 * @return char** 
 */
char	**get_argv_from_tokens(t_token *tokens, int index)
{
	char	**argv;
	int		count;
	int		i;

	argv = NULL;
	count = -1;
	i = 1;
	if (!tokens)
		return (NULL);
	count = count_args(tokens, index) + 1;
	argv = ft_calloc((count + 2), sizeof(char *));
	if (!argv)
		return (NULL);
	get_childs(tokens, argv, &i, index);
	argv[count] = NULL;
	return (argv);
}
