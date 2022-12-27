/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:47:24 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/27 22:16:48 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "./command.h"
# include "./stack.h"

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		num_of_args;
	int		*num_array;
}	t_info;

/* args */
void	ft_parse_args(t_info *info, int argc, char **argv);

/* init_stack */
void	ft_init_stack(t_info *info);

/* index_stack */
void	ft_index_stack(t_info *info);

/* sort_stack */
void	ft_sort_stack(t_info *info);

/* utils */
void	ft_print_stack(t_stack *stack);
int		ft_error(int type);
void	ft_free_array(char **arr);
void	ft_free_stack(t_stack *stack);
int		ft_check_sorted_stack(t_stack *stack);

#endif
