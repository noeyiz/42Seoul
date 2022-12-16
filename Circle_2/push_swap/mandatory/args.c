/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:42:40 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/16 21:27:46 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**ft_join_split_args(int argc, char **argv)
{
	int		idx;
	char	*temp;
	char	*join_args;
	char	**split_args;
	
	join_args = ft_strdup("");
	if (!join_args)
		return (NULL);
	idx = 1;
	while (idx < argc)
	{
		temp = ft_join_with_space(join_args, argv[idx]);
		if (!temp)
		{
			free(join_args);
			return (NULL);
		}
		free(join_args);
		join_args = temp;
		idx++;
	}
	split_args = ft_split(join_args, ' ');
	free(join_args);
	return (join_args);
}

void	ft_check_args(int argc, char **argv)
{
	char	**args;

	args = ft_join_split_args(argc, argv);
	if (!args)
		ft_print_error();
	// ft_check_int(args);
	// ft_check_dup(args);
}


// 아래의 경우 ./push_swap "1 3 2"는 ... 처리 못함

// static int	ft_count_space(char *str)
// {
// 	int	idx;

// 	idx = 0;
// 	while (str[idx] && str[idx] == ' ')
// 		idx++;
// 	return (idx);
// }

// static void	ft_check_integer(int argc, char **argv)
// {
// 	int	idx;
// 	int	move_idx;

// 	idx = 1;
// 	while (idx < argc)
// 	{
// 		move_idx = ft_count_space(argv[idx]);
// 		if (argv[idx][move_idx] == '+')
// 			move_idx++;
// 		if (ft_strncmp(argv[idx] + move_idx, \
// 		ft_itoa(ft_atoi(argv[idx])), ft_strlen(argv[idx])))
// 			ft_print_error();
// 		idx++;
// 	}
// }

// static void	ft_check_dup(int argc, char **argv)
// {
// 	int	idx1;
// 	int	idx2;
// 	int	move_idx1;
// 	int	move_idx2;

// 	idx1 = 1;
// 	while (idx1 < argc)
// 	{
// 		idx2 = 1;
// 		while (idx2 < idx1)
// 		{
// 			move_idx1 = ft_count_space(argv[idx1]);
// 			if (argv[idx1][move_idx1] == '+')
// 				move_idx1++;
// 			move_idx2 = ft_count_space(argv[idx2]);
// 			if (argv[idx2][move_idx2] == '+')
// 				move_idx2++;
// 			if (!ft_strncmp(argv[idx1] + move_idx1, argv[idx2] + move_idx2, \
// 			ft_strlen(argv[idx1] + move_idx1)))
// 				ft_print_error();
// 			idx2++;
// 		}
// 		idx1++;
// 	}
// }
