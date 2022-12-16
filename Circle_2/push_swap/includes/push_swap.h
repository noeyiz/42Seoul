/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:31:14 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/16 16:47:25 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
/* libft */
# include "../libft/libft.h"

/* args */
void	ft_check_args(int argc, char *argv[]);

/* utils */
void	ft_print_error(void);
char	*ft_join_with_space(char *s1, char *s2);

#endif
