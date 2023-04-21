/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_environment_variables.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:10 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/20 15:34:51 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	set_env_idx(char *str, int *dollar_idx, int *next_idx)
{
	*dollar_idx = 0;
	while (str[*dollar_idx] && str[*dollar_idx] != '$')
		*dollar_idx += 1;
	if (str[*dollar_idx] == '\0')
		return (0);
	*next_idx = *dollar_idx + 1;
	if (str[*next_idx] == '?' || ft_isdigit(str[*next_idx])
		|| (!ft_isalpha(str[*next_idx]) && str[*next_idx] != '_'))
	{
		*next_idx += 1;
		return (1);
	}
	if (str[*next_idx] == '\0'
		|| (!ft_isalnum(str[*next_idx]) && str[*next_idx] != '_'))
		return (0);
	while (str[*next_idx]
		&& (ft_isalnum(str[*next_idx]) || str[*next_idx] == '_'))
		*next_idx += 1;
	return (1);
}

static char	**get_exit_status_and_split(void)
{
	char	**strs;

	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	strs[0] = ft_itoa(g_exit_status);
	strs[1] = ft_strdup(" ");
	strs[2] = ft_strdup("");
	strs[3] = 0;
	return (strs);
}

static char	**interpret_and_split_env(t_env_node *env_list, char *str,
	int dollar_idx, int next_idx)
{
	char	*env_value;
	char	**strs;
	int		space_idx;

	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	env_value = ft_substr(str, dollar_idx + 1, next_idx - dollar_idx - 1);
	env_value = get_env_value_and_free_env_key(env_list, env_value);
	space_idx = 0;
	while (env_value[space_idx] && env_value[space_idx] != ' ')
		space_idx++;
	strs[0] = ft_substr(env_value, 0, space_idx);
	strs[1] = ft_strdup(" ");
	strs[2] = ft_substr(env_value, space_idx + 1,
			ft_strlen(env_value) - space_idx - 1);
	strs[3] = 0;
	free(env_value);
	return (strs);
}

char	**seperate_environment_variables(t_info *info, char *str)
{
	char	**strs;
	char	**env_value;
	int		dollar_idx;
	int		next_idx;

	if (!set_env_idx(str, &dollar_idx, &next_idx))
		return (NULL);
	strs = malloc(sizeof(char *) * 6);
	if (!strs)
		return (NULL);
	strs[0] = ft_substr(str, 0, dollar_idx);
	if (str[dollar_idx + 1] == '?')
		env_value = get_exit_status_and_split();
	else
		env_value = interpret_and_split_env(info->env_list, str,
				dollar_idx, next_idx);
	strs[1] = ft_strdup(env_value[0]);
	strs[2] = ft_strdup(env_value[1]);
	strs[3] = ft_strdup(env_value[2]);
	free_2d_arr(env_value);
	strs[4] = ft_substr(str, next_idx, ft_strlen(str) - next_idx);
	strs[5] = 0;
	return (strs);
}
