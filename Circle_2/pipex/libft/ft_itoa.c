/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:30:13 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/03 16:29:17 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsize(int n)
{
	int			size;
	long long	nbr;

	size = 0;
	nbr = (long long)n;
	if (nbr <= 0)
	{
		size++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

static char	*ft_setarr(char *arr, int n, int size)
{
	long long	nbr;

	nbr = (long long)n;
	arr[size--] = '\0';
	if (nbr < 0)
	{
		arr[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	while (nbr > 0)
	{
		arr[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*arr;

	size = ft_strsize(n);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	arr = ft_setarr(arr, n, size);
	return (arr);
}
