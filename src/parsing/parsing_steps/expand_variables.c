/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:57:44 by agras             #+#    #+#             */
/*   Updated: 2022/08/07 15:43:29 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	extract_before_key(char *data, int *i)
{
	if (!data)
		return ;
	while (data[*i] && data[*i] == ' ')
		*i += 1;
}

char	*extract_key(char *data, int *start)
{
	int	i;

	i = 0;
	if (!data)
		return (NULL);
	if (*data && *data == '?')
	{
		*start += 1;
		return (ft_strndup(data, 1));
	}
	while (data[i] && ((data[i] >= 'a' && data[i] <= 'z')
			|| (data[i] >= 'A' && data[i] <= 'Z')
			|| (data[i] >= '0' && data[i] <= '9')))
		i++;
	*start = i;
	if (i > 0)
		return (ft_strndup(data, i));
	return (NULL);
}

int	replace_with_value(t_prog *prog, t_token *token, char *value, char *after)
{
	char	*save_ptr;

	save_ptr = NULL;
	if (!value)
		ft_exit(prog, NULL, "Memory allocation failded\n");
	if (after)
	{
		save_ptr = value;
		value = ft_strjoin(value, after);
		free(save_ptr);
		free(after);
	}
	if (!value)
		ft_exit(prog, NULL, "Memory allocation failded\n");
	token->data = value;
	return (OK);
}

int	replace_key_with_value(t_prog *prog, t_token *token, char *data)
{
	int		i;
	char	*key;
	char	*after;
	char	*value;

	i = 0;
	key = extract_key(data, &i);
	after = ft_strdup(&data[i]);
	if (!after)
		ft_exit(prog, NULL, "Memory allocation failded\n");
	if (!key || !key[0])
		return (replace_with_value(prog, token, ft_strdup("$"), after));
	if (ft_strlen(key) == 1 && *key == '?')
	{
		free(key);
		return (replace_with_value(prog, token,
				ft_itoa(g_return_value), after));
	}
	value = get_env_value_by_key(prog, key);
	free(key);
	if (value)
		return (replace_with_value(prog, token, ft_strdup(value), after));
	else
		return (replace_with_value(prog, token, ft_strdup(""), after));
	return (0);
}

int	expand_variables(t_prog *prog, t_token *token)
{
	char	*save_ptr;

	if (!token)
		return (0);
	if (token->type == EXPANSION)
	{
		save_ptr = token->data;
		if (replace_key_with_value(prog, token, token->data) == FATAL_ERR)
			return (FATAL_ERR);
		free(save_ptr);
		if (token->mask[REMOVE_TOKEN_FLTR] == '1' && is_word(token->type))
			if (remove_empty_token(&token) == 1)
				return (0);
	}
	expand_variables(prog, token->left_child);
	expand_variables(prog, token->right_child);
	return (0);
}
