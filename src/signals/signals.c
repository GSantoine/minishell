/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:01:31 by recarlie          #+#    #+#             */
/*   Updated: 2022/07/26 16:39:36 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_sig(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGINT)
		display_prompt(sig);
	else if (sig == SIGQUIT)
	{
		if (info->si_pid == 0)
			backslash(sig);
		else
			ft_putstr_fd("\b\b  \b\b", 2);
	}
}

void	init_signals(t_prog *prog)
{
	struct sigaction	act;

	(void)prog;
	act.sa_sigaction = exec_sig;
	act.sa_flags = SA_SIGINFO;
	sigfillset(&act.sa_mask);
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
