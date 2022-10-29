/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:48:15 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/26 00:56:54 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_len(unsigned long long addr)
{
	int	len;

	if (addr == 0)
		return (1);
	len = 0;
	while (addr > 0)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

static void	ft_convert(unsigned long long addr, char *arr)
{
	int		len;

	len = ft_get_len(addr) + 2;
	arr[0] = '0';
	arr[1] = 'x';
	arr[len--] = '\0';
	while (len >= 2)
	{
		arr[len--] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
}

int	ft_print_ptr(unsigned long long addr)
{
	char	ptr[19];

	ft_convert(addr, ptr);
	return (ft_print_str(ptr));
}
