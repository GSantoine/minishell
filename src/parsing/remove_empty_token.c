/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_empty_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:12:18 by agras             #+#    #+#             */
/*   Updated: 2022/08/05 22:12:39 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	remove_empty_token(t_token **token)
{
	if (ft_strlen((*token)->data) > 0)
		return (0);
	if ((*token)->parent)
	{
		if ((*token)->parent->left_child == *token)
			(*token)->parent->left_child = NULL;
		if ((*token)->parent->right_child == *token)
			(*token)->parent->right_child = NULL;
	}
	free((*token)->data);
	(*token)->data = NULL;
	free(*token);
	*token = NULL;
	return (1);
}
