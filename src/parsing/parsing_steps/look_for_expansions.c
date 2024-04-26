/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_expansions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:11:17 by agras             #+#    #+#             */
/*   Updated: 2022/08/05 22:11:31 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	look_for_expansions(t_prog *prog, t_token *token)
{
	int	i;
	int	parsing_ret;

	i = 0;
	while (token->data[i])
	{
		if (is_operator(token, &token->data[i], "$", EXPAN_FLTR) != -1)
		{
			parsing_ret = parse_expansions(prog, token, &token->data[i]);
			if (parsing_ret != NOT_FOUND && parsing_ret != IGNORE)
				return (parsing_ret);
		}
		i++;
	}
	return (NOT_FOUND);
}
