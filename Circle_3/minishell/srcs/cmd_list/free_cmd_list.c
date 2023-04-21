/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:23 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:48 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_redirection_list(t_redirection *redirection_list)
{
	t_redirection	*tmp;

	while (redirection_list)
	{
		if (redirection_list->type)
			free(redirection_list->type);
		if (redirection_list->file)
			free(redirection_list->file);
		tmp = redirection_list;
		redirection_list = redirection_list->next;
		free(tmp);
	}
}

void	free_cmd_list(t_cmd **cmd_list)
{
	t_cmd	*tmp;

	while (*cmd_list)
	{
		tmp = (*cmd_list)->next;
		free_2d_arr((*cmd_list)->argv);
		free_redirection_list((*cmd_list)->redirection);
		free(*cmd_list);
		*cmd_list = tmp;
	}
}
