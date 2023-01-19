/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:09:11 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/19 10:12:10 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* str이 NULL이거나 공백문자(' ')일 때 1 리턴 */
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
			ft_error(0);
		idx++;
	}
	return (join);
}

static int	ft_atoll_if(char *str)
{
	long long	result;
	int			sign;
	int			cnt;

	result = 0;
	sign = 1;
	cnt = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		cnt++;
	}
	result *= sign;
	if (*str != '\0' || cnt > 10 || result == 0 || \
	result > 2147483647 || result < -2147483648)
		return (0);
	return (1);
}

static int	ft_check_int(char **args)
{
	int	idx;

	idx = 0;
	while (args[idx])
	{
		if (ft_atoll_if(args[idx]))
			idx++;
		else
			return (0);
	}
	return (1);
}

static void	ft_set_num_array(t_info *info, char **args)
{
	int	idx;

	idx = 0;
	info->num_of_args = 0;
	while (args[info->num_of_args])
		info->num_of_args++;
	info->num_array = (int *)malloc(sizeof(int) * info->num_of_args);
	if (info->num_array == NULL)
	{
		ft_free_array(args);
		ft_error(0);
	}
	while (idx < info->num_of_args)
	{
		info->num_array[idx] = ft_atoi(args[idx]);
		idx++;
	}
}

static int	ft_check_dup(t_info *info)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (idx1 < info->num_of_args)
	{
		idx2 = 0;
		while (idx2 < idx1)
		{
			if (info->num_array[idx1] == info->num_array[idx2])
				return (0);
			idx2++;
		}
		idx1++;
	}
	return (1);
}

void	ft_parse_args(t_info *info, int argc, char **argv)
{
	char	*join_args;
	char	**split_args;

	join_args = ft_join_args(argc, argv);
	split_args = ft_split(join_args, ' ');
	free(join_args);
	if (split_args == NULL)
		ft_error(0);
	if (ft_check_int(split_args) == 0)
	{
		ft_free_array(split_args);
		ft_error(1);
	}
	ft_set_num_array(info, split_args);
	if (ft_check_dup(info) == 0)
	{
		free(info->num_array);
		ft_error(1);
	}
}
