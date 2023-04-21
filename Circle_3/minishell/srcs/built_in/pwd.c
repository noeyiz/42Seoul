/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:05 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:44 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ms_pwd(void)
{
	char	current_working_dir[1024];

	if (getcwd(current_working_dir, 1024) == NULL)
	{
		ms_error("pwd", NULL);
		return (1);
	}
	ft_putendl_fd(current_working_dir, STDOUT_FILENO);
	return (0);
}
