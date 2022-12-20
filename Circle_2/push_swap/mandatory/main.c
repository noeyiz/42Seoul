/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:43:03 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/20 11:24:32 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	if (argc < 2)
		ft_ps_error(0);
	args = ft_trim_args(argc, argv);
	ft_verify_args(args);
	ft_init_stack(&a, &b, args);
	if (ft_check_sorted_stack(a) == FALSE)
	{
		// 인덱싱
		// 정렬
	}
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
