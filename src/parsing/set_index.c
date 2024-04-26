/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:48:59 by agras             #+#    #+#             */
/*   Updated: 2022/05/31 13:25:50 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_index(t_prog *prog, t_token *token, int index)
{
	int	index_right_child;

	if (!token)
		return ;
	index_right_child = index;
	if (token->type == PIPE)
	{
		index_right_child++;
		prog->index_max += 1;
	}
	token->index = index;
	set_index(prog, token->left_child, index);
	set_index(prog, token->right_child, index_right_child);
}
