/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_queue_management.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:53:25 by agras             #+#    #+#             */
/*   Updated: 2022/05/30 10:35:16 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_queue	*queue_new(t_type type)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	if (!new)
		return (NULL);
	new->type = type;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_queue	*queue_get_last(t_queue *queue)
{
	if (!queue)
		return (NULL);
	while (queue->next)
		queue = queue->next;
	return (queue);
}

void	queue_add_2tail(t_queue **queue, t_queue *new)
{
	t_queue	*tmp;

	if (!new)
		return ;
	new->next = NULL;
	if (!(*queue))
	{
		new->prev = NULL;
		(*queue) = new;
		return ;
	}
	tmp = queue_get_last(*queue);
	new->prev = tmp;
	tmp->next = new;
}

void	queue_delhead(t_queue **queue)
{
	t_queue	*tmp;

	if (!*queue)
		return ;
	tmp = *queue;
	if ((*queue)->next)
	{
		*queue = (*queue)->next;
		(*queue)->prev = NULL;
	}
	else
		*queue = NULL;
	free(tmp);
}

void	queue_clear(t_queue **queue)
{
	t_queue	*tmp;

	if (!*queue)
		return ;
	while (*queue)
	{
		tmp = (*queue)->next;
		queue_delhead(queue);
		*queue = tmp;
	}
}
