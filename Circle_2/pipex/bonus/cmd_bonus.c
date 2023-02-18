/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:45:59 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/18 23:33:44 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*ft_strjoin_with_space(char *s1, char *s2)
{
	int		idx;
	int		len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (len + 2));
	if (join == NULL)
		return (NULL);
	idx = 0;
	while (*s1)
		join[idx++] = *s1++;
	join[idx++] = ' ';
	while (*s2)
		join[idx++] = *s2++;
	join[idx] = '\0';
	return (join);
}

static char	*ft_join_params(char **params, int idx)
{
	char	*join;
	char	*temp;

	join = ft_strdup("");
	while (params[idx])
	{
		temp = ft_strjoin_with_space(join, params[idx]);
		free(join);
		join = temp;
		idx++;
	}
	temp = ft_substr(join, 2, ft_strlen(join) - 3);
	free(join);
	join = temp;
	return (join);
}

char	**ft_get_cmd_argv(char *str)
{
	int		i;
	int		awk_sed_flag;
	char	**cmd_argv;

	cmd_argv = ft_split(str, ' ');
	awk_sed_flag = 0;
	i = -1;
	while (cmd_argv[++i])
	{
		if (cmd_argv[i][0] == '\'' || cmd_argv[i][0] == '\"')
		{
			awk_sed_flag = 1;
			break ;
		}
	}
	if (awk_sed_flag)
	{
		cmd_argv[i] = ft_join_params(cmd_argv, i);
		cmd_argv[++i] = NULL;
	}
	return (cmd_argv);
}

char	*ft_get_cmd_file(char *cmd, char **envp)
{
	char	*cmd_file;
	char	*temp;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	temp = ft_strjoin("/", cmd);
	while (*envp)
	{
		cmd_file = ft_strjoin(*envp, temp);
		if (access(cmd_file, X_OK) == 0)
		{
			free(temp);
			return (cmd_file);
		}
		free(cmd_file);
		envp++;
	}
	free(temp);
	return (NULL);
}
