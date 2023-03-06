/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:55:22 by jikoo             #+#    #+#             */
/*   Updated: 2022/11/17 19:31:58 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static int	ft_getwordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len])
	{
		if (s[len] == c)
			break ;
		len++;
	}
	return (len);
}

static char	*ft_getword(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	len = ft_getwordlen(s, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*ft_free_all(char **s, int i)
{
	while (i--)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split_str;

	split_str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!split_str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split_str[i] = ft_getword(s, c);
			if (!split_str[i])
				ft_free_all(split_str, i - 1);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	split_str[i] = 0;
	return (split_str);
}
