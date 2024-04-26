/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:54:08 by agras             #+#    #+#             */
/*   Updated: 2022/05/26 15:54:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	identify_args(t_token *token, int is_cmd)
{
	if (!token)
		return (is_cmd);
	if (token->type == CMD)
	{
		if (is_cmd == 1)
			token->type = ARG;
		is_cmd = 1;
	}
	is_cmd = identify_args(token->left_child, is_cmd);
	if (token->type == PIPE)
		is_cmd = 0;
	is_cmd = identify_args(token->right_child, is_cmd);
	return (is_cmd);
}
