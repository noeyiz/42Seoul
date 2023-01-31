/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:22:15 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/31 13:09:44 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(char *message, int type)
{
	if (type == 0)
		ft_putstr_fd(message, 2);
	else if (type == 1)
		perror(message);
	exit(1);
}
