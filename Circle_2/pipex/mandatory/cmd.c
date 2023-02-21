/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:02:20 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/21 18:05:51 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

static char	*ft_join_params(char **params, int s_idx, int e_idx)
{
	char	*join;
	char	*temp;

	join = ft_strdup("");
	while (params[s_idx] && s_idx <= e_idx)
	{
		temp = ft_strjoin_with_space(join, params[s_idx]);
		free(join);
		free(params[s_idx]);
		join = temp;
		s_idx++;
	}
	temp = ft_substr(join, 2, ft_strlen(join) - 3);
	free(join);
	join = temp;
	return (join);
}

char	**ft_get_cmd_argv(char *str)
{
	int		i;
	int		j;
	char	c;
	char	**cmd_argv;

	cmd_argv = ft_split(str, ' ');
	i = 0;
	while (cmd_argv[i])
	{
		if (cmd_argv[i][0] == '\'' || cmd_argv[i][0] == '\"')
		{
			c = cmd_argv[i][0];
			j = 0;
			while (cmd_argv[i + j][ft_strlen(cmd_argv[i + j]) - 1] != c)
				j++;
			cmd_argv[i] = ft_join_params(cmd_argv, i, ++j);
			while (cmd_argv[++j])
				cmd_argv[++i] = cmd_argv[j];
			cmd_argv[++i] = NULL;
			break ;
		}
		i++;
	}
	return (cmd_argv);
}

char	*ft_get_cmd_file(char *cmd, char **envps)
{
	char	*cmd_file;
	char	*temp;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	temp = ft_strjoin("/", cmd);
	while (*envps)
	{
		cmd_file = ft_strjoin(*envps, temp);
		if (access(cmd_file, X_OK) == 0)
		{
			free(temp);
			return (cmd_file);
		}
		free(cmd_file);
		envps++;
	}
	free(temp);
	return (NULL);
}
