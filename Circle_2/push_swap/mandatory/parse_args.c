/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:09:11 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/28 21:08:04 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isempty(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] != ' ')
			return (0);
		idx++;
	}
	return (1);
}

static char	*ft_strjoin_with_space(char *s1, char *s2)
{
	int		idx;
	int		len;
	char	*join;

	if (!s1 || !s2 || ft_isempty(s2))
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

static char	*ft_join_args(int argc, char **argv)
{
	int		idx;
	char	*join;
	char	*temp;

	idx = 1;
	join = ft_strdup("");
	while (idx < argc)
	{
		temp = ft_strjoin_with_space(join, argv[idx]);
		free(join);
		join = temp;
		if (join == NULL)
			ft_error(ERR_TYPE_ETC);
		idx++;
	}
	return (join);
}

void	ft_parse_args(t_info *info, int argc, char **argv)
{
	char	*join_args;
	char	**split_args;

	join_args = ft_join_args(argc, argv);
	split_args = ft_split(join_args, ' ');
	free(join_args);
	if (split_args == NULL)
		ft_error(ERR_TYPE_ETC);
	if (ft_check_int(split_args) == 0)
	{
		ft_free_array(split_args);
		ft_error(ERR_TYPE_SUBJECT);
	}
	ft_set_num_array(info, split_args);
	ft_free_array(split_args);
	if (ft_check_dup(info) == 0)
	{
		free(info->num_array);
		ft_error(ERR_TYPE_SUBJECT);
	}
}
