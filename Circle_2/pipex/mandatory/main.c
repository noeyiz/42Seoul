/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:01:50 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/31 15:36:19 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	
	if (argc < 5)
		ft_exit("Invalid number of arguments!\n", 0);
	ft_parse_args(&info, argv, envp);
	return (0);
}
