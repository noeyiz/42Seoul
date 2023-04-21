/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:29 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/21 17:47:32 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_env_value_if(t_env_node *env_list, char *str,
	int *dollar_idx, int *next_idx)
{
	*next_idx = *dollar_idx + 1;
	if (str[*next_idx] == '?')
	{
		*next_idx += 1;
		return (ft_itoa(g_exit_status));
	}
	if (str[*next_idx] == '\0' || !ft_isalnum(str[*next_idx]))
		return (NULL);
	while (str[*next_idx]
		&& (ft_isalnum(str[*next_idx]) || str[*next_idx] == '_'))
		*next_idx += 1;
	return (get_env_value_and_free_env_key(env_list,
			ft_substr(str, *dollar_idx + 1, *next_idx - *dollar_idx - 1)));
}

static void	handle_heredoc_env(t_env_node *env_list, int fd, char *str)
{
	int		start_idx;
	int		end_idx;
	char	*env_value;

	start_idx = 0;
	end_idx = 0;
	while (str[end_idx])
	{
		if (str[end_idx] == '$')
		{
			write(fd, str + start_idx, end_idx - start_idx);
			start_idx = end_idx;
			env_value = get_env_value_if(env_list, str, &start_idx, &end_idx);
			if (env_value)
			{
				write(fd, env_value, ft_strlen(env_value));
				start_idx = end_idx;
				free(env_value);
			}
		}
		else
			end_idx++;
	}
	write(fd, str + start_idx, end_idx - start_idx);
}

static void	ms_heredoc(t_env_node *env_list, char *file_name, char *limiter)
{
	int		fd;
	char	*input;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	signal(SIGINT, heredoc_handler);
	while (1)
	{
		input = readline("> ");
		if (input == NULL)
			ft_putstr_fd("\033[1A\033[2C", STDOUT_FILENO);
		if (input == NULL || (ft_strlen(input) == ft_strlen(limiter)
				&& ft_strncmp(input, limiter, ft_strlen(input)) == 0))
		{
			close(fd);
			return ;
		}
		handle_heredoc_env(env_list, fd, input);
		write(fd, "\n", 1);
		free(input);
	}
	close(fd);
	free(input);
}

void	execute_heredoc(t_info *info, t_cmd *cmd_list)
{
	t_redirection	*cur;
	int				cnt;
	char			*file_cnt;
	char			*file_name;

	cnt = 0;
	while (cmd_list)
	{
		cur = cmd_list->redirection;
		while (cur)
		{
			if (ft_strncmp(cur->type, "<<", 2) == 0)
			{
				file_cnt = ft_itoa(cnt);
				file_name = ft_strjoin(file_cnt, ".tmp");
				ms_heredoc(info->env_list, file_name, cur->file);
				free_strs(file_cnt, file_name, NULL, NULL);
			}
			cur = cur->next;
		}
		cmd_list = cmd_list->next;
		cnt++;
	}
	exit(0);
}

void	unlink_heredoc_tmp(t_cmd *cmd_list)
{
	int		cnt;
	char	*file_cnt;
	char	*file_name;

	cnt = 0;
	while (cmd_list)
	{
		file_cnt = ft_itoa(cnt);
		file_name = ft_strjoin(file_cnt, ".tmp");
		unlink(file_name);
		free_strs(file_cnt, file_name, NULL, NULL);
		cmd_list = cmd_list->next;
		cnt++;
	}
}
