/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:29:16 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/26 00:48:07 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_run(va_list *ap, const char *format);
int		ft_parse(va_list *ap, char type);

int		ft_strlen(char *str);
void	*ft_itoa_base(long long n, char *arr, char *base);

int		ft_print_chr(int c);
int		ft_print_str(char *str);
int		ft_print_dec(long long n);
int		ft_print_hex(long long n, int flag);
int		ft_print_ptr(unsigned long long n);

#endif
