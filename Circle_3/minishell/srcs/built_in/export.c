/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:48:02 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/21 17:51:26 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	change_value_if_key_exist(t_info *info, char *key, char *value)
{
	t_env_node	*cur;

	cur = info->env_list;
	while (cur)
	{
		if (ft_strlen(cur->key) == ft_strlen(key) \
		&& ft_strncmp(cur->key, key, ft_strlen(key)) == 0)
		{
			if (ft_strncmp(key, "PATH", 4) == 0)
			{
				free_2d_arr(info->path_list);
				info->path_list = ft_split(value, ':');
			}
			if (value)
			{
				if (cur->value)
					free(cur->value);
				cur->value = ft_strdup(value);
			}
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

static void	print_env_list(t_env_node *env_list)
{
	while (env_list)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env_list->key, STDOUT_FILENO);
		if (env_list->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(env_list->value, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		env_list = env_list->next;
	}
}

static int	is_valid_key(char *key)
{
	int	idx;

	if (ft_isalpha(key[0]) == 0 && key[0] != '_' )
		return (0);
	idx = 0;
	while (key[++idx])
		if (ft_isalnum(key[idx]) == 0 && key[idx] != '_')
			return (0);
	return (1);
}

static int	set_error_flag(t_env_node *env_node, char *str, int *error_flag)
{
	char	*key;

	key = env_node->key;
	if (!is_valid_key(key))
	{
		ft_putstr_fd("minishell: export: \'", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putendl_fd("\': not a valid identifier", STDERR_FILENO);
		free_env_list(env_node);
		*error_flag = 1;
		return (1);
	}
	return (0);
}

int	ms_export(t_info *info, char **argv)
{
	int			idx;
	t_env_node	*new;
	int			error_flag;

	idx = 0;
	error_flag = 0;
	while (argv[++idx])
	{
		if (argv[idx][0] == '\0')
			continue ;
		new = create_env_node(argv[idx]);
		if (set_error_flag(new, argv[idx], &error_flag))
			continue ;
		else if (change_value_if_key_exist(info, new->key, new->value))
			free_env_list(new);
		else
		{
			if (ft_strncmp(new->key, "PATH", 4) == 0)
				info->path_list = ft_split(new->value, ':');
			add_env_node(&info->env_list, new);
		}
	}
	if (idx == 1)
		print_env_list(info->env_list);
	return (error_flag);
}
