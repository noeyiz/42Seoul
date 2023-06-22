/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:55:49 by jikoo             #+#    #+#             */
/*   Updated: 2023/05/31 14:51:30 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_size_and_sign(long long *n, int *size, int *is_minus);

char	*ft_itoa(int n)
{
	int			idx;
	int			size;
	int			is_minus;
	long long	lln;
	char		*result;

	lln = (long long)n;
	set_size_and_sign(&lln, &size, &is_minus);
	result = malloc(sizeof(char) * (is_minus + size + 1));
	if (result == NULL)
		return (NULL);
	if (is_minus)
		result[0] = '-';
	idx = is_minus + size;
	result[idx] = '\0';
	while (--idx >= is_minus)
	{
		result[idx] = lln % 10 + '0';
		lln /= 10;
	}
	return (result);
}

static void	set_size_and_sign(long long *n, int *size, int *is_minus)
{
	long long	lln;

	*size = 0;
	*is_minus = 0;
	if (*n < 0)
	{
		*n *= -1;
		*is_minus = 1;
	}
	lln = *n;
	if (lln == 0)
		*size += 1;
	while (lln > 0)
	{
		lln /= 10;
		*size += 1;
	}
}
