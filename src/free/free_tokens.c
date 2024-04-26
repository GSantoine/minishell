/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:58:42 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:44:08 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Reverse-recursive function to free tokens from t_prog.
 * 
 * @param tokens 
 */
void	free_tokens(t_token **tokens)
{
	if (!(*tokens))
		return ;
	if ((*tokens)->left_child)
		free_tokens(&((*tokens)->left_child));
	if ((*tokens)->right_child)
		free_tokens(&((*tokens)->right_child));
	if ((*tokens)->data)
	{
		free((*tokens)->data);
		(*tokens)->data = NULL;
	}
	if ((*tokens)->mask)
	{
		free((*tokens)->mask);
		(*tokens)->mask = NULL;
	}
	if ((*tokens))
		free((*tokens));
	(*tokens) = NULL;
}
