/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:36:49 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/05 18:07:02 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	interactive_mode(t_prog *prog, int c, char **a)
{
	if (c == 1)
	{
		prog->interactive = 0;
		return (1);
	}
	if (c > 3)
		exit(0 * ft_putstr_fd("Too many arguments\n", 2));
	if (c < 1)
		exit(0 * ft_putstr_fd("Too few arguments\n", 2));
	if (c == 2)
		exit(0 * ft_putstr_fd("Usage: ./minishell [-c command]\n", 2));
	if (ft_strncmp(a[1], "-c", 2) == 0 && a[1][2] == '\0')
	{
		prog->interactive = 1;
		return (1);
	}
	else
		exit(0 * ft_putstr_fd("Usage: ./minishell [-c command]\n", 2));
}
