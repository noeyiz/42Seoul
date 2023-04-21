/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_space_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:07 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/21 17:51:44 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_space_token(t_token **token_list)
{
	t_token	**head;
	t_token	*cur;

	head = token_list;
	cur = *token_list;
	while (cur)
	{
		if (cur->type == TOKEN_TYPE_SPACE)
		{
			cur = delete_token(cur, head);
			continue ;
		}
		cur = cur->next;
	}
}
