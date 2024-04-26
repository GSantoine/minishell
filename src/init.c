/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:32:50 by agras             #+#    #+#             */
/*   Updated: 2022/08/05 18:56:47 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_parsing_hierarchy(t_prog *prog)
{
	prog->parsing_filters[OPEN_DQUOTES_FLTR] = parse_opening_double_quote;
	prog->parsing_filters[CLOSE_DQUOTES_FLTR] = parse_closing_double_quote;
	prog->parsing_filters[OPEN_SQUOTES_FLTR] = parse_opening_single_quote;
	prog->parsing_filters[CLOSE_SQUOTES_FLTR] = parse_closing_single_quote;
	prog->parsing_filters[PIPE_FLTR] = parse_pipes;
	prog->parsing_filters[DREDIR_IN_FLTR] = parse_dredir_in;
	prog->parsing_filters[DREDIR_OUT_FLTR] = parse_dredir_out;
	prog->parsing_filters[REDIR_IN_FLTR] = parse_redir_in;
	prog->parsing_filters[REDIR_OUT_FLTR] = parse_redir_out;
	prog->parsing_filters[SPACE_FLTR] = parse_spaces;
	prog->parsing_filters[EXPAN_FLTR] = parse_expansions;
}
