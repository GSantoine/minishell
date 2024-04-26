/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remodel_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 22:00:24 by agras             #+#    #+#             */
/*   Updated: 2022/08/05 22:02:09 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_prev_token_ignored_zone(t_token *token, t_token **prev_token,
	int *i)
{
	int	j;

	j = 0;
	while (j < (*prev_token)->ignore_slots_total)
	{
		token->ignore_this[*i].start = (*prev_token)->ignore_this[j].start
			+ ft_strlen(token->data);
		token->ignore_this[*i].end = (*prev_token)->ignore_this[j].end
			+ ft_strlen(token->data);
		*i += 1;
		j++;
	}
	(*prev_token)->type = NA;
}

void	set_ignored_zone(t_token *token, int *i)
{
	token->ignore_this[*i].start = 0;
	token->ignore_this[*i].end = ft_strlen(token->data);
	*i += 1;
}

int	fusion_tokens(t_token *token, char **right_part, t_token **prev_token)
{
	int		i;
	char	*save_ptr;

	i = 0;
	save_ptr = NULL;
	if (token->mask[SPACE_FLTR] == '1')
		set_ignored_zone(token, &i);
	if (!*right_part)
		*right_part = token->data;
	else
	{
		if (*prev_token)
			add_prev_token_ignored_zone(token, prev_token, &i);
		token->ignore_slots_total = i;
		save_ptr = token->data;
		token->data = ft_strjoin(token->data, *right_part);
		if (!token->data)
			return (FATAL_ERR);
		if (save_ptr)
			free(save_ptr);
		*right_part = token->data;
	}
	*prev_token = token;
	return (OK);
}

int	assemble_tokens(t_token *token, char **right_part,
	t_token **prev_token, t_type type)
{
	if (!token)
		return (OK);
	if (assemble_tokens(token->right_child, right_part,
			prev_token, type) == FATAL_ERR)
		return (FATAL_ERR);
	if (is_priority_operator(token->type))
	{
		*right_part = NULL;
		*prev_token = NULL;
	}
	if (assemble_tokens(token->left_child, right_part,
			prev_token, type) == FATAL_ERR)
		return (FATAL_ERR);
	if ((!token->left_child && !token->right_child) && is_word(token->type))
		if (fusion_tokens(token, right_part, prev_token) == FATAL_ERR)
			return (FATAL_ERR);
	return (OK);
}

int	remodel_parsing(t_token *token)
{
	char	*right_part;
	t_token	*prev_token;
	t_type	type;

	right_part = NULL;
	prev_token = NULL;
	type = CMD;
	return (assemble_tokens(token, &right_part, &prev_token, type));
}
