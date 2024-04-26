/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 20:20:08 by agras             #+#    #+#             */
/*   Updated: 2022/08/05 20:40:09 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_priority_operator(t_type type)
{
	if (type == WHITESPACE || type == PIPE)
		return (1);
	if (type == REDIR_IN || type == REDIR_OUT)
		return (1);
	if (type == DREDIR_IN || type == DREDIR_OUT)
		return (1);
	return (0);
}

int	is_word(t_type type)
{
	if (type == CMD || type == DQUOTES
		|| type == SQUOTES || type == EXPANSION
		|| type == OUTFILE || type == INFILE
		|| type == HEREDOC || type == APPEND_OUTFILE)
		return (1);
	return (0);
}
