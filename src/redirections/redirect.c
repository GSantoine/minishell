/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:42:07 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	block_cmd(t_prog *prog, int index, t_token *token)
{
	prog->r_failed[index] = 1;
	if (token->type == CMD && token->index == index)
		token->doable = 0;
	if (token->left_child)
		block_cmd(prog, index, token->left_child);
	if (token->right_child)
		block_cmd(prog, index, token->right_child);
}

/**
 * @brief Not used anymore since redir tokens data are now the filename.
 * 
 */
char	*get_filename(char *line, char sep)
{
	int		i;
	char	**tab;
	char	*filename;

	i = 0;
	tab = ft_split(line, sep);
	while (tab[i])
		i++;
	filename = trim_spaces(tab[i - 1]);
	ft_free_char_array(tab, 1);
	i = 0;
	return (filename + i);
}

/**
 * @brief Redirect the input of the command to a file. The function will get the
 * filename from the tokens. If the file does not exist the function will
 * display an error message. If the file exists, the function will redirect the
 * input of the command to the file.
 * 
 * @param prog 
 * @return int 
 */
void	redir_in(t_prog *prog, t_token *token)
{
	int		fd;

	if (prog->r_failed[token->index])
		return ;
	fd = open(token->data, O_RDONLY);
	if (fd == -1)
	{
		g_return_value = 1;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(token->data, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		block_cmd(prog, token->index, prog->tokens);
	}
	if (token->index == prog->index_max && prog->index_max > 0)
	{
		if (prog->redir_fds[token->index - 1][REND] > 0)
			close(prog->redir_fds[token->index - 1][REND]);
		prog->redir_fds[token->index - 1][REND] = fd;
	}
	else
	{
		if (prog->redir_fds[token->index][REND] > 0)
			close(prog->redir_fds[token->index][REND]);
		prog->redir_fds[token->index][REND] = fd;
	}
}

/**
 * @brief Redirect the output of the command to a file. The function will get the
 * filename from the tokens. If the file does not exist the function will
 * create the file. If the file exists, the function will redirect the output of
 * the command to the file.
 * 
 * @param prog 
 * @return int 
 */
void	redir_out(t_prog *prog, t_token *token)
{
	int		fd;

	if (prog->r_failed[token->index])
		return ;
	fd = open(token->data, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		g_return_value = 1;
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(token->data, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		block_cmd(prog, token->index, prog->tokens);
	}
	if (prog->redir_fds[token->index][WEND] > 1)
		close(prog->redir_fds[token->index][WEND]);
	prog->redir_fds[token->index][WEND] = fd;
}

/**
 * @brief Redirect the output of the command, but append the content of the file
 * to the file. The function will get the filename from the tokens. If the file
 * does not exist, the function will create the file and redirect the output of
 * the command to the file.
 * 
 * @param prog 
 * @return int 
 */
void	redir_out_append(t_prog *prog, t_token *token)
{
	int		fd;

	if (prog->r_failed[token->index])
		return ;
	fd = open(token->data, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(token->data, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		block_cmd(prog, token->index, prog->tokens);
	}
	if (prog->redir_fds[token->index][WEND] > 1)
		close(prog->redir_fds[token->index][WEND]);
	prog->redir_fds[token->index][WEND] = fd;
}
