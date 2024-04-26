/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_parsing_queue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:04:16 by agras             #+#    #+#             */
/*   Updated: 2022/05/20 16:12:06 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_queue	*dup_parsing_queue(t_queue *queue)
{
	t_queue	*new;

	new = NULL;
	while (queue)
	{
		queue_add_2tail(&new, queue_new(queue->type));
		queue = queue->next;
	}
	return (new);
}
