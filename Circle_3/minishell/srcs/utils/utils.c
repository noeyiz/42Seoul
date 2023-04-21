/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:43 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:50 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_error(char *blame, char *blame2)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(blame, STDERR_FILENO);
	if (blame2)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(blame2, STDERR_FILENO);
	}
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

int	is_tokenable_sep(char c)
{
	return (c == ' ' || c == '|' || c == '<' || c == '>' || c == '\0');
}

char	**env_list_to_envp(t_env_node *env_list)
{
	char		**envp;
	int			size;
	int			idx;
	t_env_node	*tmp;

	tmp = env_list;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	if (size == 0)
		return (NULL);
	envp = malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	idx = -1;
	while (++idx < size)
	{
		envp[idx] = join_strs(env_list->key, "=", env_list->value);
		env_list = env_list->next;
	}
	envp[idx] = 0;
	return (envp);
}

void	free_2d_arr(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}
