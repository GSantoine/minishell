/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specify_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:13:26 by agras             #+#    #+#             */
/*   Updated: 2022/08/05 22:13:38 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	specify_tokens(t_token *token)
{
	if (!token)
		return ;
	if (!token->left_child && !token->right_child && is_word(token->type))
		token->type = token->master_type;
	specify_tokens(token->left_child);
	specify_tokens(token->right_child);
}
