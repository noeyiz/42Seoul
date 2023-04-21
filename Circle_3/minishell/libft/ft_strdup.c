/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 00:01:24 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/27 16:53:57 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strdup() function allocates sufficient memory for a copy of the string
 * s1, does the copy, and returns a pointer to it.  The pointer may
 * subsequently be used as an argument to the function free(3).

 * If insufficient memory is available, NULL is returned and errno is set to
 * ENOMEM.
 */
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, len);
	str[len] = '\0';
	return (str);
}
