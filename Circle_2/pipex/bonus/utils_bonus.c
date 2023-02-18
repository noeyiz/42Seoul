/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:48:26 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/18 23:50:34 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exit(char *message, int status)
{
	perror(message);
	exit(status);
}

int	ft_check_heredoc(t_info *info, char *str)
{
	if (str && ft_strncmp(str, "here_doc", ft_strlen(str)) == 0)
		info->is_heredoc = 1;
	else
		info->is_heredoc = 0;
	return (info->is_heredoc);
}
