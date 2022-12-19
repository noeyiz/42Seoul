/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:25:39 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/19 20:39:16 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 서브젝트에 명시되어있는 오류의 경우 1, NULL 예외처리는 -1, 그 외에는 0을 리턴 */
int	ft_print_error(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit(1);
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_deque	a;
	t_deque	b;
	char	**args;

	if (argc < 2)
		ft_print_error(0);
	ft_trim_args(argc, argv, &args);
	ft_verify_args(args);
	ft_init_stack(&a, &b, args);
	return (0);
}
