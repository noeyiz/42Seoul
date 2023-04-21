/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:19 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:51 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**fill_argv(t_token *token_list)
{
	int		idx;
	char	**argv;

	argv = (char **)malloc(sizeof(char *) * (get_argv_cnt(token_list) + 1));
	if (!argv)
		return (NULL);
	idx = 0;
	while (token_list && token_list->type != TOKEN_TYPE_PIPELINE)
	{
		if (token_list->type == TOKEN_TYPE_ARGV)
			argv[idx++] = ft_strdup(token_list->string);
		else if (token_list->type == TOKEN_TYPE_REDIRECTION)
			token_list = token_list->next;
		token_list = token_list->next;
	}
	argv[idx] = NULL;
	return (argv);
}

static void	fill_redirection(t_token *token_list, t_cmd **cmd_list)
{
	t_redirection	*cur;

	if (!(*cmd_list)->redirection)
		(*cmd_list)->redirection = make_redirection_node(token_list);
	else
	{
		cur = (*cmd_list)->redirection;
		while (cur->next)
			cur = cur->next;
		cur->next = make_redirection_node(token_list);
	}
}

t_cmd	*create_cmd_list(t_token *token_list)
{
	t_cmd	*cmd_list;
	t_cmd	*head;

	cmd_list = make_cmd_node();
	head = cmd_list;
	while (token_list)
	{
		if (cmd_list->argv == NULL && token_list->type == TOKEN_TYPE_ARGV)
			cmd_list->argv = fill_argv(token_list);
		else if (token_list->type == TOKEN_TYPE_REDIRECTION)
		{
			fill_redirection(token_list, &cmd_list);
			token_list = token_list->next;
		}
		else if (token_list->type == TOKEN_TYPE_PIPELINE)
		{
			cmd_list->next = make_cmd_node();
			cmd_list->next->prev = cmd_list;
			cmd_list = cmd_list->next;
		}
		token_list = token_list->next;
	}
	return (head);
}
