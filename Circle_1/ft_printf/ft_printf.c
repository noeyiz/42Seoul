/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:24:48 by jikoo             #+#    #+#             */
/*   Updated: 2022/09/06 16:20:27 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list *ap, char type)
{
	if (type == 'c')
		return (ft_print_chr(va_arg(*ap, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(*ap, unsigned long long)));
	else if (type == 'd' || type == 'i')
		return (ft_print_dec(va_arg(*ap, int)));
	else if (type == 'u')
		return (ft_print_dec(va_arg(*ap, unsigned int)));
	else if (type == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), 0));
	else if (type == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), 1));
	else if (type == '%')
		return (ft_print_chr('%'));
	else
		return (-1);
}

int	ft_run(va_list *ap, const char *format)
{
	int	i;
	int	count;
	int	check;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			check = write(1, &format[i], 1);
		else if (format[++i] != '\0')
			check = ft_parse(ap, format[i]);
		if (check < 0)
			return (-1);
		count += check;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = ft_run(&ap, format);
	va_end(ap);
	return (cnt);
}
