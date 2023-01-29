/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:58:37 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 21:23:07 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	ft_execute_command(t_info *info, char *command)
{
	if (ft_strncmp(command, "sa\n", 3) == 0)
		ft_sa(info);
	else if (ft_strncmp(command, "sb\n", 3) == 0)
		ft_sb(info);
	else if (ft_strncmp(command, "ss\n", 3) == 0)
		ft_ss(info);
	else if (ft_strncmp(command, "pa\n", 3) == 0)
		ft_pa(info);
	else if (ft_strncmp(command, "pb\n", 3) == 0)
		ft_pb(info);
	else if (ft_strncmp(command, "ra\n", 3) == 0)
		ft_ra(info);
	else if (ft_strncmp(command, "rb\n", 3) == 0)
		ft_rb(info);
	else if (ft_strncmp(command, "rr\n", 3) == 0)
		ft_rr(info);
	else if (ft_strncmp(command, "rra\n", 4) == 0)
		ft_rra(info);
	else if (ft_strncmp(command, "rrb\n", 4) == 0)
		ft_rrb(info);
	else if (ft_strncmp(command, "rrr\n", 4) == 0)
		ft_rrr(info);
	else
		return (0);
	return (1);
}

void	ft_run_checker(t_info *info)
{
	int		is_executed;
	int		is_sorted;
	char	*command;

	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
			break ;
		is_executed = ft_execute_command(info, command);
		free(command);
		command = NULL;
		if (is_executed == 0)
		{
			ft_free_stack(info->a);
			ft_free_stack(info->b);
			ft_exit(EXIT_TYPE_ERR);
		}
	}
	is_sorted = ft_check_sorted_stack(info->a);
	ft_free_stack(info->a);
	ft_free_stack(info->b);
	if (is_sorted == 0 || info->b->size > 0)
		ft_exit(EXIT_TYPE_KO);
	ft_exit(EXIT_TYPE_OK);
}
