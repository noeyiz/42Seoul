/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:47:57 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:46 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ms_atoll_if(char *str, long long *n)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	if (sign == -1 && ft_strlen(str) == 19 \
	&& ft_strncmp(str, "9223372036854775808", 19) == 0)
	{
		*n = -9223372036854775807 - 1;
		return (1);
	}
	while (ft_isdigit(*str) && num * 10 + (*str - '0') >= num)
		num = num * 10 + (*str++ - '0');
	if (*str)
		return (0);
	*n = sign * num;
	return (1);
}

static void	set_exit_status(int arg_cnt, char *str)
{
	long long	exit_status;

	if (arg_cnt == 2)
	{
		if (ms_atoll_if(str, &exit_status))
			g_exit_status = (unsigned char)exit_status;
		else
		{
			ft_putstr_fd("minishell: exit: ", STDOUT_FILENO);
			ft_putstr_fd(str, STDOUT_FILENO);
			ft_putendl_fd(": numeric argument required", STDOUT_FILENO);
			g_exit_status = 255;
		}
	}
	else
		g_exit_status = 0;
}

int	ms_exit(t_info *info, t_cmd *cmd_list)
{
	int	arg_cnt;

	dup2(info->stdout, STDOUT_FILENO);
	if (cmd_list)
	{
		arg_cnt = 0;
		while (cmd_list->argv[arg_cnt])
			arg_cnt++;
		if (cmd_list->prev == NULL && cmd_list->next == NULL)
			ft_putendl_fd("exit", STDOUT_FILENO);
		if (arg_cnt > 2)
		{
			ft_putendl_fd("minishell: exit: too many arguments", STDOUT_FILENO);
			return (1);
		}
		set_exit_status(arg_cnt, cmd_list->argv[1]);
		unlink_heredoc_tmp(cmd_list);
		free_cmd_list(&cmd_list);
	}
	else
		ft_putendl_fd("exit", STDOUT_FILENO);
	free_env_list(info->env_list);
	free_2d_arr(info->path_list);
	exit(g_exit_status);
	return (0);
}
