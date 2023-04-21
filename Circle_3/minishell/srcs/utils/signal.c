/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:36 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/20 15:07:07 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_handler(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		ft_putendl_fd("", STDERR_FILENO);
		exit(1);
	}
}

void	quit_handler(int signum)
{
	if (signum == SIGINT)
		ft_putendl_fd("", STDERR_FILENO);
	exit(1);
}

static void	default_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putendl_fd(CYAN"💎 minishell-1.0$ "RESET, STDOUT_FILENO);
		g_exit_status = 1;
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	set_signal(void)
{
	signal(SIGINT, default_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
