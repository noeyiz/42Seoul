/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:15 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/20 15:43:27 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	set_env_in_quotes_idx(char *str, int *dollar_idx, int *next_idx)
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

static char	*interpret_env_from_d_quotes(t_info *info, char *str)
{
	char	*str_arr[3];
	int		dollar_idx;
	int		next_idx;

	while (set_env_in_quotes_idx(str, &dollar_idx, &next_idx))
	{
		str_arr[0] = ft_substr(str, 0, dollar_idx);
		if (str[dollar_idx + 1] == '?')
		{
			next_idx = dollar_idx + 2;
			str_arr[1] = ft_itoa(g_exit_status);
		}
		else
		{
			str_arr[1] = ft_substr(str, dollar_idx + 1,
					next_idx - dollar_idx - 1);
			str_arr[1] = get_env_value_and_free_env_key(info->env_list,
					str_arr[1]);
		}
		str_arr[2] = ft_substr(str, next_idx, ft_strlen(str) - next_idx);
		free(str);
		str = join_strs(str_arr[0], str_arr[1], str_arr[2]);
		free_strs(str_arr[0], str_arr[1], str_arr[2], NULL);
	}
	return (str);
}

static int	set_quotes_idxs(t_info *info, char *str,
	int *start_idx, int *end_idx)
{
	*start_idx = 0;
	while (str[*start_idx] && str[*start_idx] != '\''
		&& str[*start_idx] != '\"')
		*start_idx += 1;
	if (str[*start_idx] == '\0')
		return (0);
	*end_idx = *start_idx + 1;
	while (str[*end_idx] && str[*end_idx] != str[*start_idx])
		*end_idx += 1;
	if (str[*end_idx] == '\0')
	{
		ft_putstr_fd("minishell: quotes error\n", STDERR_FILENO);
		info->syntax_error = 1;
		return (0);
	}
	return (1);
}

char	**seperate_quotes(t_info *info, char *str)
{
	char	**strs;
	int		start_idx;
	int		end_idx;

	if (!set_quotes_idxs(info, str, &start_idx, &end_idx))
		return (NULL);
	strs = malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	if (start_idx > 0 && str[start_idx - 1] == '$')
		strs[0] = ft_substr(str, 0, start_idx - 1);
	else
		strs[0] = ft_substr(str, 0, start_idx);
	strs[1] = ft_substr(str, start_idx + 1, end_idx - start_idx - 1);
	if (str[start_idx] == '\"')
		strs[1] = interpret_env_from_d_quotes(info, strs[1]);
	strs[2] = ft_substr(str, end_idx + 1, ft_strlen(str) - end_idx - 1);
	strs[3] = 0;
	return (strs);
}
