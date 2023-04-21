/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_token_by_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:22 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:52:22 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	set_arg_idxs(char *str, char *arg, int *start_idx, int *end_idx)
{
	while (str[*start_idx] && ft_strncmp(str + *start_idx, arg, ft_strlen(arg)))
		*start_idx += 1;
	if (str[*start_idx] == '\0')
		return ;
	*end_idx = *start_idx + ft_strlen(arg);
}

static char	**seperate_by_arg(char *str, char *arg)
{
	char	**strs;
	int		start_idx;
	int		end_idx;

	start_idx = 0;
	end_idx = -1;
	set_arg_idxs(str, arg, &start_idx, &end_idx);
	if (start_idx > end_idx)
		return (NULL);
	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(str, 0, start_idx);
	strs[1] = ft_substr(str, start_idx, end_idx - start_idx);
	strs[2] = ft_substr(str, end_idx, ft_strlen(str) - end_idx);
	strs[3] = 0;
	return (strs);
}

static void	convert_result_to_token(t_token *token_list, char **strs, char *arg)
{
	t_token	*temp;

	temp = token_list->next;
	token_list->next = NULL;
	free(token_list->string);
	token_list->string = ft_strdup(strs[0]);
	if (arg[0] == ' ')
		add_token(&token_list, create_token(strs[1], TOKEN_TYPE_SPACE));
	else if (arg[0] == '|')
		add_token(&token_list, create_token(strs[1], TOKEN_TYPE_PIPELINE));
	else
		add_token(&token_list, create_token(strs[1], TOKEN_TYPE_REDIRECTION));
	token_list = add_token(&token_list, create_token(strs[2],
				TOKEN_TYPE_CHUNK));
	free_2d_arr(strs);
	token_list->next = temp;
}

// CHUNK => CHUNK, ???, CHUNK
void	seperate_token_by_arg(t_token *token_list, char *arg)
{
	char	**strs;

	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			strs = seperate_by_arg(token_list->string, arg);
			if (strs)
				convert_result_to_token(token_list, strs, arg);
		}
		token_list = token_list->next;
	}
}
