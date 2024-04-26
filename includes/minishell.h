/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:18:56 by agras             #+#    #+#             */
/*   Updated: 2022/08/07 16:07:24 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>

# define ERROR_PIPE "minishell: syntax error near unexpected token `|'\n"
# define ERROR_DIR "No such file or directory\n"
# define ERROR_HOME "minishell: cd: HOME not set\n"
# define ERROR_CMD "command not found\n"
# define MALLOC_FAILED "malloc failed\n"
# define FATAL_ERR -1
# define IGNORE 2
# define NOT_FOUND 1
# define OK 0
# define ULL_MAX 9223372036854775807u

# define PARSING_STEPS_NB 14
# define OPEN_DQUOTES_FLTR 0
# define CLOSE_DQUOTES_FLTR 1
# define OPEN_SQUOTES_FLTR 2
# define CLOSE_SQUOTES_FLTR 3
# define PIPE_FLTR 4
# define DREDIR_IN_FLTR 5
# define DREDIR_OUT_FLTR 6
# define REDIR_IN_FLTR 7
# define REDIR_OUT_FLTR 8
# define SPACE_FLTR 9
# define EXPAN_FLTR 10
# define TRIM_SPACES_FLTR 11
# define IGNORE_QUOTES_FLTR 12
# define REMOVE_TOKEN_FLTR 13

# define OPEN_MASK "11111111111111"
# define DQUOTING_MASK "01000000001000"
# define SQUOTING_MASK "00010000001000"
# define IN_DQUOTES_MASK "00000000001000"
# define IN_SQUOTES_MASK "00000000000000"
# define INEXPANSION_MASK "00000000011101"

# define D_QUOTE '\"'
# define QUOTE '\''
# define D_QUOTE_S "\""
# define QUOTE_S "\'"
# define LEFT 0
# define RIGHT 1

# define IGNORE_SLOTS 100

# ifndef RETURN_VALUE
#  define RETURN_VALUE
/**
 * @brief [GLOBAL] Return value of echo $?.
 * 
 */
extern int	g_return_value;

# endif

# define COLOR "\001\033[0;34m\002"
# define WHITE "\001\033[0m\002"

/**
 * @brief Structure used in prompt_new(), more modularity to add colors.
 * 
 */
typedef struct s_colors {
	char	*color;
	char	*white;
}	t_colors;

typedef enum e_pipes {
	REND,
	WEND,
	REND_CPY
}	t_pipes;

typedef enum e_type {
	OPEN_DQUOTES,
	CLOSE_DQUOTES,
	OPEN_SQUOTES,
	CLOSE_SQUOTES,
	DQUOTES,
	SQUOTES,
	PIPE,
	DREDIR_IN,
	DREDIR_OUT,
	REDIR_IN,
	REDIR_OUT,
	INFILE,
	OUTFILE,
	HEREDOC,
	APPEND_OUTFILE,
	WHITESPACE,
	OPEN,
	EXPAND,
	EXPANSION,
	CMD,
	ARG,
	NA
}	t_type;

typedef struct s_queue {
	t_type			type;
	struct s_queue	*prev;
	struct s_queue	*next;
}			t_queue;

typedef struct s_zone {
	int	start;
	int	end;
}			t_zone;

typedef struct s_token {
	t_type			type;
	t_type			master_type;
	char			*data;
	int				index;
	t_zone			ignore_this[IGNORE_SLOTS];
	int				ignore_slots_total;
	int				doable;
	char			*mask;
	struct s_token	*parent;
	struct s_token	*left_child;
	struct s_token	*right_child;
}	t_token;

typedef struct s_metachar {
	char	*symbol;
	t_type	type;
}			t_metachar;

typedef struct s_env {
	char	**key;
	char	**value;
	int		size;
}	t_env;

/**
 * @brief Program structure.
 * 
 * @param[in] line Line obtained from prompt
 */
typedef struct s_prog {
	char		**args;
	int			args_count;
	int			fatal_error;
	int			fd_in;
	int			interactive;
	pid_t		*pids;
	int			fd_out;
	int			fd_err;
	int			redir_count;
	int			pipe_count;
	int			pid;
	int			**redir_fds;
	int			**pipes;
	int			index_max;
	char		*home;
	char		*line;
	int			line_index;
	char		*filename;
	char		*filename_err;
	char		**path;
	int			previous_index_max;
	int			heredoc_count;
	char		**heredoc_names;
	int			*r_failed;
	t_token		*tokens;
	t_env		*env;
	t_env		*env_exp;
	int			(*parsing_filters[PARSING_STEPS_NB])(struct s_prog *prog,
			t_token *token, char *line);
	char		*metachars[PARSING_STEPS_NB];
	t_queue		*parsing_queue;
}	t_prog;

int		interactive_mode(t_prog *prog, int c, char **a);

t_queue	*queue_new(t_type type);
t_queue	*queue_get_last(t_queue *queue);
void	queue_add_2tail(t_queue **queue, t_queue *new);

// TOKEN MANAGEMENT

t_token	*token_new(char *data, t_type type, t_type master, char *parent_mask);
int		token_add_left_child(t_token **parent, t_token *new);
int		token_add_right_child(t_token **parent, t_token *new);

// PARSING QUEUE MANAGEMENT

t_queue	*queue_new(t_type type);
t_queue	*queue_get_last(t_queue *queue);
void	queue_add_2tail(t_queue **queue, t_queue *new);
void	queue_delhead(t_queue **queue);
t_queue	*dup_parsing_queue(t_queue *queue);

// PARSER
void	treat(t_prog *prog);
char	*trim_spaces(char *data);
char	*trim_begin_spaces(char *line);
void	trim_end_spaces(char *line);
int		count_cmds(char *line);
int		line_length(char *line);
int		init_parser(t_prog *prog);
int		parse_cmd(t_prog *prog, t_token *token);
void	parse_checker(t_prog *prog);
int		parse_pipes(t_prog *prog, t_token *token, char *line);
int		parse_spaces(t_prog *prog, t_token *token, char *line);
int		parse_dredir_in(t_prog *prog, t_token *token, char *line);
int		parse_dredir_out(t_prog *prog, t_token *token, char *line);
int		parse_redir_in(t_prog *prog, t_token *token, char *line);
int		parse_redir_out(t_prog *prog, t_token *token, char *line);
int		parse_redirs(t_prog *prog, t_token *token, char *line);
int		parse_closing_double_quote(t_prog *prog, t_token *token, char *line);
int		parse_closing_single_quote(t_prog *prog, t_token *token, char *line);
int		parse_opening_double_quote(t_prog *prog, t_token *token, char *line);
int		parse_opening_single_quote(t_prog *prog, t_token *token, char *line);
int		parse_expansions(t_prog *prog, t_token *token, char *line);
int		parse_remaining_spaces(t_prog *prog, t_token *token);
int		find_remaining_spaces(t_prog *prog, t_token *token);
int		expand_variables(t_prog *prog, t_token *token);
int		remodel_parsing(t_token *token);
int		look_for_pipes_n_redirs(t_prog *prog, t_token *token);
int		look_for_quotes(t_prog *prog, t_token *token);
int		look_for_expansions(t_prog *prog, t_token *token);
void	look_for_metachars(t_token *token, char *line);
int		remove_empty_token(t_token **token);
int		is_cmd(t_token *token);
int		is_arg(t_token *token);
void	set_index(t_prog *prog, t_token *token, int index);
int		ignore_until(char *line, char until_this, int *i);
int		remove_quotes(char *line, char to_find);
void	set_index(t_prog *prog, t_token *token, int index);
int		ignore_quotes(char *line, int *i);
int		identify_args(t_token *token, int is_cmd);
int		is_priority_operator(t_type type);
int		is_word(t_type type);
int		remove_empty_token(t_token **token);
void	specify_tokens(t_token *token);

// TOKENIZER
char	*get_token_data(t_prog *prog);
t_type	get_token_enum(t_prog *prog, t_token *token);
int		get_data_length(t_prog *prog);

// CLEANING
void	clear_token(t_token *token);

// SIGNALS
void	init_signals(t_prog *prog);
void	backslash(int sig);
void	cancel(int sig);
void	display_prompt(int sig);

// BUILTINS
int		ft_cd(t_prog *prog, char **args, t_token *token);
void	ft_pwd(t_prog *prog, t_token *token);
void	ft_exit(t_prog *prog, char **args, char *msg);
void	ft_export(t_prog *prog, char **args, int free_args, t_token *token);
void	ft_unset(t_prog *prog, char **args);
void	ft_echo(t_prog *prog, char **args, t_token *token);
void	ft_env(t_prog *prog, t_token *token);
int		get_new_env_size(t_prog *prog, char **args);
int		get_env_exp_size(t_prog *prog);
int		get_env_size(t_prog *prog);
void	duplicate_env(t_prog *prog, t_env *new_env);
void	add_in_env_exp(t_prog *prog, char *val);
void	add_in_env(t_prog *prog, char *val);
char	*get_env_value_by_key(t_prog *prog, char *key);
char	*get_env_value_from_str(char *str);
char	*get_env_key_from_str(char *str);
void	edit_value_by_key(t_env *env, char *key, char *new_val);
void	print_env_exp(t_prog *prog, t_token *token);
int		get_env_key_index(char *key, t_env *env);
t_env	*malloc_env(int size);
void	ft_custom_exit(t_prog *prog, int exit_code, char *str, int mallocd);
void	ft_setenv(t_prog *prog, char **args);
void	ft_export_norm(t_prog *prog, char **args, char *key, int i);
void	init_new_env(t_prog *prog);

// INIT
void	init_env(t_prog *prog, char **env);
void	init_parsing_hierarchy(t_prog *prog);
int		init_metachars(t_prog *prog);
int		init_pids(t_prog *prog);
void	init_path(t_prog *prog, char **env);
void	init_pipes(t_prog *prog, int index_max);
void	init_redirs(t_prog *prog, int index_max);
void	init_heredocs(t_prog *prog);

// UTILS

int		is_operator(t_token *token, char *line, char *metachar, int index);
int		search_for_metachar(char *line, char *metachar);
char	*ft_strndup(char *str, int len);
char	*get_env_value(char *str);
char	*get_env_key(char *str);

// FREE
void	free_path(t_prog *prog);
void	free_tokens(t_token **tokens);
void	free_pids(t_prog *prog);
void	free_pipes(t_prog *prog);
void	free_prog(t_prog *prog);
void	free_env(t_prog *prog);
void	free_redirs(t_prog *prog);
void	free_line(t_prog *prog);
void	free_env_exp(t_prog *prog);
void	free_heredocs(t_prog *prog);
void	ft_free_int_array(t_prog *prog, int freecont);

// EXEC
int		exec_prog(t_prog *prog, t_token *token);
int		exec_cmd(t_prog *prog, char **env, t_token *token);
void	exec_builtin(t_prog *prog, char **args, t_token *token);
int		is_builtin(char *cmd);
char	**get_argv_from_tokens(t_token *tokens, int index);
int		count_args(t_token *token, int index);
char	*get_cmd_path(t_prog *prog, char *cmd);
void	exec_pipe(t_prog *prog, t_token *tokens, char **env);
void	close_child_pipes(t_prog *prog, int index);
void	print_argv(char **argv);
void	exec_command_child_fork(t_prog *prog, t_token *tokens);
void	close_pipes(t_prog *prog);
void	exec_not_builtin(t_prog *prog, char **argv);
void	exec_index_not_max(t_prog *prog, t_token *tokens);
void	exec_index_zero(t_prog *prog, t_token *tokens);
void	exec_index_max(t_prog *prog, t_token *tokens);
char	**get_env(t_prog *prog, t_env *env);
void	reset_path(t_prog *prog, char *path);

// FD HANDLERS
void	close_further_fds(t_prog *prog, int index);
void	close_fds_parent(t_prog *prog, int index);

// TOKEN TYPE HANDLER
void	check_token(t_prog *prog, t_token *token, int index);
void	check_pipe(t_prog *prog, t_token *token);
void	check_redir(t_prog *prog, t_token *token);
void	check_cmd(t_prog *prog, t_token *token);
void	check_heredoc(t_prog *prog, t_token *token);

// REDIR
void	add_fd(t_prog *prog, int fd);
void	redir_in(t_prog *prog, t_token *token);
void	redir_out(t_prog *prog, t_token *token);
void	redir_out_append(t_prog *prog, t_token *token);
int		heredoc(t_prog *prog, t_token *token);

// TO DELETE
void	print_tokens(t_token *tokens);
int		count_spaces_head(char *line);

// DEBUG FUNCTIONS

void	print_parsing(t_token *token, char *which_child);
void	print_queue(t_queue *queue);
void	print_type(t_type type);

#endif
