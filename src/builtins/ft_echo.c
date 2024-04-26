/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:29:23 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_last_arg(char **args, int i)
{
	int	is_last;

	is_last = 1;
	while (args[i + 1])
	{
		is_last = 0;
		i++;
	}
	return (is_last);
}

int	is_flag_n(char *str)
{
	int	i;

	i = 1;
	if (!str || !str[0])
		return (0);
	if (str[0] == '-')
	{
		while (str[i] == 'n')
			i++;
		if (str[i] == '\0' && str[i - 1] == 'n')
			return (1);
	}
	return (0);
}

void	print_echo_args(t_prog *prog, char **args, int i, t_token *token)
{
	int	fd;

	fd = STDOUT_FILENO;
	if (prog->index_max == 0)
		fd = prog->redir_fds[token->index][WEND];
	while (args[i])
	{
		ft_putstr_fd(args[i], fd);
		if (!is_last_arg(args, i))
			ft_putchar_fd(' ', fd);
		i++;
	}
}

void	trailing_newline(char **args, int *i, int *jump)
{
	*jump = 1;
	*i = 1;
	while (args[*i])
	{
		if (is_flag_n(args[*i]))
			*jump = 0;
		else
			break ;
		*i += 1;
	}
}

void	ft_echo(t_prog *prog, char **args, t_token *token)
{
	int	i;
	int	jump;
	int	fd;

	fd = STDOUT_FILENO;
	if (prog->index_max == 0)
		fd = prog->redir_fds[token->index][WEND];
	trailing_newline(args, &i, &jump);
	print_echo_args(prog, args, i, token);
	if (jump)
		ft_putchar_fd('\n', fd);
	g_return_value = 0;
	if (prog->index_max > 0)
	{
		ft_free_char_array(args, 1);
		exit(0);
	}
}
