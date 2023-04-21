/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:47:48 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:42 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_env(t_env_node *env_list)
{
	while (env_list)
	{
		if (env_list->value)
		{
			ft_putstr_fd(env_list->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putendl_fd(env_list->value, STDOUT_FILENO);
		}
		env_list = env_list->next;
	}
	return (0);
}
