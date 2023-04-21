/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:14 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:45 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*make_cmd_node(void)
{
	t_cmd	*cmd_node;

	cmd_node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd_node)
		return (NULL);
	cmd_node->argv = NULL;
	cmd_node->redirection = NULL;
	cmd_node->prev = NULL;
	cmd_node->next = NULL;
	return (cmd_node);
}

t_redirection	*make_redirection_node(t_token *token_list)
{
	t_redirection	*node;

	node = (t_redirection *)malloc(sizeof(t_redirection));
	node->type = ft_strdup(token_list->string);
	node->file = ft_strdup(token_list->next->string);
	node->next = NULL;
	return (node);
}

int	get_argv_cnt(t_token *token_list)
{
	int	cnt;

	cnt = 0;
	while (token_list && token_list->type != TOKEN_TYPE_PIPELINE)
	{
		if (token_list->type == TOKEN_TYPE_ARGV)
			cnt++;
		else if (token_list->type == TOKEN_TYPE_REDIRECTION)
			cnt--;
		token_list = token_list->next;
	}
	return (cnt);
}
