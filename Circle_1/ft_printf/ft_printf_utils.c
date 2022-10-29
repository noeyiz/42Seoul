/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:43:03 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/26 00:51:12 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char	*ft_convert(long long n, char *arr, char *base, int size)
{
	int	base_len;

	base_len = ft_strlen(base);
	arr[size--] = '\0';
	if (n < 0)
	{
		arr[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		arr[0] = base[0];
		return (arr);
	}
	while (n > 0)
	{
		arr[size--] = base[n % base_len];
		n /= base_len;
	}
	return (arr);
}

void	*ft_itoa_base(long long n, char *arr, char *base)
{
	int			size;
	int			base_len;
	long long	tmp;

	size = 0;
	base_len = ft_strlen(base);
	tmp = n;
	if (tmp <= 0)
	{
		size++;
		tmp = -tmp;
	}
	while (tmp > 0)
	{
		size++;
		tmp /= base_len;
	}
	return (ft_convert(n, arr, base, size));
}
