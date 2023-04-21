/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 22:49:33 by jikoo             #+#    #+#             */
/*   Updated: 2023/04/19 22:54:53 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_node	*create_env_node(char *str)
{
	t_env_node	*env_node;
	int			equal_idx;

	env_node = malloc(sizeof(t_env_node));
	if (!env_node)
		return (NULL);
	equal_idx = 0;
	while (str[equal_idx] && str[equal_idx] != '=')
		equal_idx++;
	env_node->key = ft_substr(str, 0, equal_idx);
	if (str[equal_idx] != '\0')
		env_node->value = ft_substr(str, equal_idx + 1,
				ft_strlen(str) - equal_idx - 1);
	else
		env_node->value = NULL;
	env_node->next = NULL;
	return (env_node);
}

void	add_env_node(t_env_node **env_list, t_env_node *new_env_node)
{
	t_env_node	*env_list_ptr;

	if (!*env_list)
	{
		*env_list = new_env_node;
		return ;
	}
	env_list_ptr = *env_list;
	while (env_list_ptr->next)
		env_list_ptr = env_list_ptr->next;
	env_list_ptr->next = new_env_node;
}

t_env_node	*init_env_list(char **envp)
{
	t_env_node	*env_list;

	env_list = NULL;
	while (*envp)
		add_env_node(&env_list, create_env_node(*envp++));
	return (env_list);
}

char	*get_env_value_and_free_env_key(t_env_node *env_list, char *env_key)
{
	char	*env_value;

	while (env_list && (ft_strlen(env_list->key) != ft_strlen(env_key) \
	|| ft_strncmp(env_list->key, env_key, ft_strlen(env_list->key))))
		env_list = env_list->next;
	if (env_list)
		env_value = ft_strdup(env_list->value);
	else
		env_value = ft_strdup("");
	free(env_key);
	return (env_value);
}

void	free_env_list(t_env_node *env_list)
{
	t_env_node	*temp;

	while (env_list)
	{
		temp = env_list;
		env_list = env_list->next;
		free(temp->key);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
}
