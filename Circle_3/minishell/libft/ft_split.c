/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:17:46 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/07 01:23:57 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_num_of_words(char const *s, char c);
static int	ft_get_word_len(char const *s, char c);
static char	*ft_free_all(char **s, int i);

/**
 * The ft_split() function allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the character ’c’ as
 * a delimiter. The array must end with a NULL pointer.
 */
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	str = malloc(sizeof(char *) * (ft_get_num_of_words(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[i] = ft_strndup(s, ft_get_word_len(s, c));
			if (!str[i])
				ft_free_all(str, i - 1);
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	str[i] = 0;
	return (str);
}

static int	ft_get_num_of_words(char const *s, char c)
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

static int	ft_get_word_len(char const *s, char c)
{
	char const	*s_ptr;

	s_ptr = s;
	while (*s_ptr && *s_ptr != c)
		s_ptr++;
	return (s_ptr - s);
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
