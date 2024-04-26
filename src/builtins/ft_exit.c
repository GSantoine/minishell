/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:29:50 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_arg(char *arg)
{
	int		i;
	int		valid;

	i = 0;
	valid = 1;
	if (!arg)
		return (1);
	if (arg[i] == '-')
	{
		i++;
		valid = 1;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			valid = 0;
		else if (i == 1 && ft_isdigit(arg[i]))
			valid = 1;
		i++;
	}
	return (valid);
}

void	ft_custom_exit(t_prog *prog, int exit_code, char *str, int mallocd)
{
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
	if (mallocd)
		free(str);
	free_prog(prog);
	g_return_value = exit_code;
	exit(g_return_value);
}

void	invalid_args(t_prog *prog, char *str, int return_value)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": numeric argument required", 2);
	free_prog(prog);
	exit(return_value);
}

void	too_many_args(t_prog *prog)
{
	ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	free_prog(prog);
	exit(1);
}

void	ft_exit(t_prog *prog, char **args, char *str)
{
	static int			count_args = 0;
	unsigned long long	exit_code;

	if (!str)
		write(2, "", 0);
	else
		ft_putstr_fd(str, STDERR_FILENO);
	if (args)
		while (args[count_args])
			count_args++;
	if (count_args >= 2)
	{
		if (!is_valid_arg(args[1]))
			invalid_args(prog, args[1], 2);
		if (count_args > 2)
			too_many_args(prog);
		exit_code = ft_atoull(args[1]);
		if ((exit_code > ULL_MAX && ft_isdigit(args[1][0])) ||
			(args[1][0] == '-' && ft_atoull(&args[1][1]) > ULL_MAX + 1))
			invalid_args(prog, args[1], 2);
		else
			g_return_value = (unsigned char)ft_atoi(args[1]) % 256;
	}
	free_prog(prog);
	exit(g_return_value);
}
