/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:28 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:47 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_pipeline_syntax(t_token *token_list)
{
	t_token	*prev;

	prev = NULL;
	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_PIPELINE)
		{
			if (prev == NULL || token_list->next == NULL
				|| token_list->next->type == TOKEN_TYPE_PIPELINE)
			{
				ft_putstr_fd("minishell: syntax error near unexpected"
					"token \'|\'\n", STDERR_FILENO);
				return (1);
			}
		}
		prev = token_list;
		token_list = token_list->next;
	}
	return (0);
}

static int	check_redirection_syntax(t_token *token_list)
{
	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_REDIRECTION)
		{
			if (token_list->next == NULL
				|| token_list->next->type != TOKEN_TYPE_ARGV)
			{
				ft_putstr_fd("minishell: syntax error near unexpected"
					"token \'newline\'\n", STDERR_FILENO);
				return (1);
			}
		}
		token_list = token_list->next;
	}
	return (0);
}

int	syntax_analysis(t_token *token_list)
{
	return (check_pipeline_syntax(token_list)
		|| check_redirection_syntax(token_list));
}
