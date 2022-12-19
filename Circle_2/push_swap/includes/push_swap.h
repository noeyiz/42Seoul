/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:31:14 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/19 18:49:54 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
/* libft */
# include "../libft/libft.h"

/* args */
void	ft_parse_args(int argc, char **argv, char ***args);

int		ft_print_error(int type);

/* utils */
int		ft_atoll(char *str, int *ret_n);
void	ft_free_array(char **arr);

#endif
