/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:47 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:41 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// CHUNK => ARGV
void	handle_chunk(t_token **token_list)
{
	t_token	**head;
	t_token	*cur;

	head = token_list;
	cur = *token_list;
	while (cur)
	{
		if (cur->type == TOKEN_TYPE_CHUNK)
		{
			if (cur->string[0] != '\0')
			{
				cur->type = TOKEN_TYPE_ARGV;
				cur = cur->next;
			}
			else
				cur = delete_token(cur, head);
		}
		else
			cur = cur->next;
	}
}
