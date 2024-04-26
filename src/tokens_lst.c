/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:35:42 by agras             #+#    #+#             */
/*   Updated: 2022/08/07 15:34:45 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*fusion_masks(char *new_mask, char *parent_mask)
{
	int	i;

	i = 0;
	if (!new_mask)
		return (NULL);
	if (!parent_mask)
		return (new_mask);
	while (new_mask[i])
	{
		if (parent_mask[i] == '0')
			new_mask[i] = '0';
		i++;
	}
	return (new_mask);
}

char	*create_mask(t_type type, char *parent_mask)
{
	if (type == OPEN_DQUOTES)
		return (fusion_masks(ft_strdup(DQUOTING_MASK), parent_mask));
	if (type == OPEN_SQUOTES)
		return (fusion_masks(ft_strdup(SQUOTING_MASK), parent_mask));
	if (type == DQUOTES)
		return (fusion_masks(ft_strdup(IN_DQUOTES_MASK), parent_mask));
	if (type == SQUOTES)
		return (fusion_masks(ft_strdup(IN_SQUOTES_MASK), parent_mask));
	if (type == EXPANSION)
		return (fusion_masks(ft_strdup(INEXPANSION_MASK), parent_mask));
	return (fusion_masks(ft_strdup(OPEN_MASK), parent_mask));
}

t_token	*token_new(char *data, t_type type, t_type master, char *parent_mask)
{
	t_token	*new;

	if (!data)
		return (NULL);
	new = malloc(sizeof(t_token));
	if (!new)
	{
		free(data);
		return (NULL);
	}
	new->type = type;
	new->master_type = master;
	new->data = data;
	new->index = 0;
	new->ignore_slots_total = 0;
	new->doable = 1;
	new->mask = create_mask(type, parent_mask);
	if (!new->mask)
		return (NULL);
	new->parent = NULL;
	new->left_child = NULL;
	new->right_child = NULL;
	return (new);
}

int	token_add_left_child(t_token **parent, t_token *new)
{
	if (!new)
		return (FATAL_ERR);
	new->left_child = NULL;
	new->right_child = NULL;
	if (!(*parent))
	{
		new->parent = NULL;
		(*parent) = new;
		return (0);
	}
	new->parent = *parent;
	(*parent)->left_child = new;
	return (OK);
}

int	token_add_right_child(t_token **parent, t_token *new)
{
	if (!new)
		return (FATAL_ERR);
	new->left_child = NULL;
	new->right_child = NULL;
	if (!(*parent))
	{
		new->parent = NULL;
		(*parent) = new;
		return (0);
	}
	new->parent = *parent;
	(*parent)->right_child = new;
	return (OK);
}
