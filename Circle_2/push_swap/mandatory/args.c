/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 20:29:39 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/19 18:50:33 by jikoo            ###   ########.fr       */
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

static char	*ft_strjoin_w_space(char *s1, char *s2)
{
	int		idx;
	int		len;
	char	*join_str;

	if (!s1 || !s2 || ft_isempty(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!join_str)
		return (NULL);
	idx = 0;
	while (*s1)
		join_str[idx++] = *s1++;
	join_str[idx++] = ' ';
	while (*s2)
		join_str[idx++] = *s2++;
	join_str[idx] = '\0';
	return (join_str);
}

static void	ft_check_int(char **arr)
{
	int	idx;
	int	atoll_n;

	idx = 0;
	while (arr[idx])
	{
		if (ft_atoll(arr[idx], &atoll_n))
			idx++;
		else
		{
			ft_free_array(arr);
			ft_print_error(1);
		}	
	}
}

static void	ft_check_dup(char **arr)
{
	int		idx_1;
	int		idx_2;
	int		offset_1;
	int		offset_2;

	idx_1 = -1;
	while (arr[++idx_1])
	{
		idx_2 = -1;
		offset_1 = 0;
		if (arr[idx_1][0] == '+')
			offset_1 = 1;
		while (++idx_2 < idx_1)
		{
			offset_2 = 0;
			if (arr[idx_2][0] == '+')
				offset_2 = 1;
			if (ft_strncmp(arr[idx_1] + offset_1, arr[idx_2] + \
			offset_2, ft_strlen(arr[idx_1] + offset_1)) == 0)
			{
				ft_free_array(arr);
				ft_print_error(1);
			}
		}
	}
}

void	ft_parse_args(int argc, char **argv, char ***args)
{
	int		idx;
	char	*join;
	char	*temp;

	idx = 1;
	join = ft_strdup("");
	while (idx < argc)
	{
		temp = ft_strjoin_w_space(join, argv[idx]);
		free(join);
		join = temp;
		if (!join)
			ft_print_error(-1);
		idx++;
	}
	*args = ft_split(join, ' ');
	free(join);
	if (!*args)
		ft_print_error(-1);
	ft_check_int(*args);
	ft_check_dup(*args);
}
