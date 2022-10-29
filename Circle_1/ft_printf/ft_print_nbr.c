/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:10:08 by jikoo             #+#    #+#             */
/*   Updated: 2022/09/01 14:29:06 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(long long n)
{
	char	dec[12];

	ft_itoa_base(n, dec, "0123456789");
	return (ft_print_str(dec));
}

int	ft_print_hex(long long n, int flag)
{
	char	hex[9];

	if (flag)
		ft_itoa_base(n, hex, "0123456789ABCDEF");
	else
		ft_itoa_base(n, hex, "0123456789abcdef");
	return (ft_print_str(hex));
}
