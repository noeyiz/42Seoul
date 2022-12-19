/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:33:57 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/20 05:24:35 by jikoo            ###   ########.fr       */
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
			return (FALSE);
		idx++;
	}
	return (TRUE);
}

static char	*ft_strjoin_with_space(char *s1, char *s2)
{
	int		idx;
	int		len;
	char	*join_str;

	if (!s1 || !s2 || ft_isempty(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *)malloc(sizeof(char) * (len + 2));
	if (join_str == NULL)
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

char	**ft_trim_args(int argc, char **argv)
{
	int		idx;
	char	*join;
	char	*temp;
	char	**args;

	idx = 1;
	join = ft_strdup("");
	while (idx < argc)
	{
		temp = ft_strjoin_with_space(join, argv[idx]);
		free(join);
		join = temp;
		if (join == NULL)
			ft_ps_error(-1);
		idx++;
	}
	args = ft_split(join, ' ');
	free(join);
	if (args == NULL)
		ft_ps_error(-1);
	return (args);
}
