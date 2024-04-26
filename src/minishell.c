/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:55:21 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	call_readline(t_prog *prog, char **a)
{
	prog->pipe_count = 0;
	rl_outstream = stderr;
	init_signals(prog);
	prog->redir_count = 0;
	prog->redir_fds = NULL;
	if (!prog->interactive)
		prog->line = readline("$> ");
	else
		prog->line = ft_strdup(a[2]);
}

int	g_return_value;

void	waitpids(t_prog *prog)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (!prog->pids)
		return ;
	while (i <= prog->index_max)
	{
		if (prog->pids[i] != 0)
		{
			waitpid(prog->pids[i], &status, 0);
			g_return_value = 0;
			if (WEXITSTATUS(status) != 0)
			{
				if (WEXITSTATUS(status) > 127)
					g_return_value = WEXITSTATUS(status) - 127;
				else
					g_return_value = WEXITSTATUS(status);
			}
		}
		i++;
	}
}

void	init_all(t_prog *prog, char **env, char **av, int ac)
{
	init_path(prog, env);
	prog->env = NULL;
	init_env(prog, env);
	prog->args = av;
	prog->args_count = ac;
	prog->fatal_error = 0;
	prog->line = NULL;
	prog->pids = NULL;
	prog->pipes = NULL;
	prog->index_max = 0;
	prog->tokens = NULL;
	prog->redir_count = 0;
	prog->line = NULL;
	prog->index_max = 0;
	prog->heredoc_count = 0;
	prog->heredoc_names = NULL;
	prog->redir_fds = NULL;
}

void	minishell(t_prog *prog)
{
	if (ft_strlen(prog->line) > 0 && !prog->interactive)
		add_history(prog->line);
	init_pipes(prog, prog->index_max);
	init_pids(prog);
	prog->r_failed = ft_calloc(prog->index_max + 1, sizeof(int));
	if (prog->r_failed == NULL)
		ft_exit(prog, NULL, "minishell: failed to allocate memory\n");
	if (prog->tokens)
		if (prog->tokens->data)
			exec_prog(prog, prog->tokens);
	waitpids(prog);
	ft_free_int_array(prog, 1);
	free_redirs(prog);
	free_line(prog);
	free_tokens(&prog->tokens);
	free_pids(prog);
	free_pipes(prog);
	free_heredocs(prog);
}

int	main(int c, char **a, char **env)
{
	t_prog	prog;

	if (interactive_mode(&prog, c, a) < 0)
		return (0);
	init_all(&prog, env, a, c);
	while (1)
	{
		call_readline(&prog, a);
		if (!prog.line)
			ft_exit(&prog, NULL, NULL);
		if (init_parser(&prog) == -1)
		{
			g_return_value = 2;
			if (prog.interactive)
				break ;
			else
				continue ;
		}
		minishell(&prog);
		if (prog.interactive)
			break ;
	}
	free_prog(&prog);
	return (g_return_value);
}
