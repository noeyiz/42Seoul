/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc_limiter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:54 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:41 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	handle_quotes_in_limiter(t_info *info, t_token *list,
	char *s, int start_idx)
{
	int		offset;
	char	*string;

	offset = 1;
	while (s[start_idx + offset] && s[start_idx + offset] != s[start_idx])
		offset++;
	if (s[start_idx + offset] == '\0')
	{
		ft_putstr_fd("minishell: quotes error\n", STDERR_FILENO);
		info->syntax_error = 1;
	}
	string = ft_substr(s, start_idx + 1, offset - 1);
	if (string[0] != '\0')
		add_token(&list, create_token(string, TOKEN_TYPE_ARGV));
	free(string);
	return (start_idx + offset + 1);
}

static int	handle_heredoc_arg(t_info *info,
	t_token *list, char *s, int start_idx)
{
	int		offset;
	char	*string;

	while (s[start_idx] && !is_tokenable_sep(s[start_idx]))
	{
		if (s[start_idx] == '\'' || s[start_idx] == '\"')
			start_idx = handle_quotes_in_limiter(info, list, s, start_idx);
		else
		{
			offset = 1;
			while (s[start_idx + offset]
				&& !is_tokenable_sep(s[start_idx + offset])
				&& s[start_idx + offset] != '\''
				&& s[start_idx + offset] != '\"')
				offset++;
			string = ft_substr(s, start_idx, offset);
			add_token(&list, create_token(string, TOKEN_TYPE_ARGV));
			start_idx += offset;
			free(string);
		}
	}
	return (start_idx);
}

static int	set_limiter_start_idx(char *s)
{
	int	idx;
	int	offset;

	idx = 0;
	while (s[idx] && ft_strncmp(s + idx, "<<", 2))
	{
		offset = 1;
		if (s[idx] == '\'' || s[idx] == '\"')
		{
			while (s[idx + offset] && s[idx + offset] != s[idx])
				offset++;
			offset++;
		}
		idx += offset;
	}
	return (idx);
}

static void	init_heredoc(t_info *info, t_token *list, char *s)
{
	int		start_idx;
	char	*string;

	start_idx = set_limiter_start_idx(s);
	if (s[start_idx] == '\0')
	{
		free(s);
		return ;
	}
	start_idx += 2;
	while (s[start_idx] == ' ')
		start_idx++;
	free(list->string);
	list->string = ft_substr(s, 0, start_idx);
	start_idx = handle_heredoc_arg(info, list, s, start_idx);
	string = ft_substr(s, start_idx, ft_strlen(s) - start_idx);
	add_token(&list, create_token(string, TOKEN_TYPE_CHUNK));
	free_strs(string, s, NULL, NULL);
}

// CHUNK => CHUNK(<<), ARGV(limiter), CHUNK
void	handle_heredoc_limiter(t_info *info, t_token *token_list)
{
	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
			init_heredoc(info, token_list, ft_strdup(token_list->string));
		token_list = token_list->next;
	}
}
