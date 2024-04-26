/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:53:15 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:37:54 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_error(char *limit)
{
	ft_putstr_fd("heredoc: document delimited by end-of-file, wanted : ", 2);
	ft_putstr_fd(limit, 2);
	ft_putstr_fd("\n", 2);
}

void	open_new_heredoc(t_prog *prog, t_token *token, int fd)
{
	int		new_fd;

	new_fd = open(prog->heredoc_names[token->index], O_RDWR, 0644);
	if (fd == -1)
		ft_exit(prog, NULL, "heredoc: you did something nasty. Exit cleanly.");
	if (token->index == prog->index_max && prog->index_max > 0)
	{
		if (prog->redir_fds[token->index - 1][REND] > 0)
			close(prog->redir_fds[token->index - 1][REND]);
		prog->redir_fds[token->index][REND] = new_fd;
	}
	else if (prog->index_max > 0)
	{
		if (prog->redir_fds[token->index][REND] > 0)
			close(prog->redir_fds[token->index][REND]);
		prog->redir_fds[token->index + 1][REND] = new_fd;
	}
}

/**
 * @brief Read on the standard input until the limiter is found.
 * 
 */
void	execute_heredoc(t_prog *prog, t_token *token, int fd, char *h_name)
{
	char	*tmp;

	prog->heredoc_names[token->index] = h_name;
	open_new_heredoc(prog, token, fd);
	signal(SIGQUIT, SIG_IGN);
	tmp = readline("");
	if (tmp == NULL)
		heredoc_error(token->data);
	while (tmp != NULL && ft_strncmp(tmp, token->data, ft_strlen(tmp)) != 0)
	{
		ft_putendl_fd(tmp, fd);
		free(tmp);
		tmp = readline("");
		if (tmp == NULL)
		{
			heredoc_error(token->data);
			break ;
		}
	}
	signal(SIGQUIT, backslash);
	if (tmp)
		free(tmp);
	close(fd);
}

/**
 * @brief Reproduce the behavior of heredoc in bash.
 * 
 * @param prog 
 * @return void 
 */
void	check_heredoc(t_prog *prog, t_token *token)
{
	int		fd;
	char	*h_name;

	if (prog->r_failed[token->index] || token->type != HEREDOC)
		return ;
	h_name = ft_calloc(255, sizeof(char));
	if (h_name == NULL)
		ft_exit(prog, NULL, "heredoc: malloc failed\n");
	ft_strlcat(h_name, ".heredoc", 255);
	fd = open(h_name, O_RDONLY);
	while (fd != -1 && ft_strlen(h_name) < 255
		&& ft_strlcat(h_name, "0", 255))
	{
		close(fd);
		fd = open(h_name, O_RDWR | 0666);
	}
	if (ft_strlen(h_name) >= 255)
		ft_exit(prog, NULL, "heredoc: couldn't create file, wp.\n");
	if (fd != -1)
		close(fd);
	fd = open(h_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (prog->heredoc_names[token->index] != NULL)
		free(prog->heredoc_names[token->index]);
	execute_heredoc(prog, token, fd, h_name);
}
