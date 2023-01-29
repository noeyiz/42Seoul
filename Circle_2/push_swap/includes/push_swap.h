/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:47:24 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/29 17:47:55 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*tail;
}	t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		num_of_args;
	int		*num_array;
}	t_info;

/* commands */
void	ft_sa(t_info *info);
void	ft_sb(t_info *info);
void	ft_ss(t_info *info);
void	ft_pa(t_info *info);
void	ft_pb(t_info *info);
void	ft_ra(t_info *info);
void	ft_rb(t_info *info);
void	ft_rr(t_info *info);
void	ft_rra(t_info *info);
void	ft_rrb(t_info *info);
void	ft_rrr(t_info *info);

/* stack_operator */
void	ft_push_front(t_stack *stack, t_node *new);
void	ft_push_back(t_stack *stack, t_node *new);
t_node	*ft_pop_front(t_stack *stack);
t_node	*ft_pop_back(t_stack *stack);

/* args */
void	ft_parse_args(t_info *info, int argc, char **argv);
int		ft_check_int(char **args);
void	ft_set_num_array(t_info *info, char **args);
int		ft_check_dup(t_info *info);

/* create_stack */
t_node	*ft_create_node(int data);
t_stack	*ft_create_stack(void);

/* init_stack */
void	ft_init_stack(t_info *info);

/* sort_stack */
void	ft_sort_stack(t_info *info);
void	ft_move_from_b_to_a(t_info *info);
int		ft_find_location(t_stack *stack, int index);

/* utils */
int		ft_abs(int n);
int		ft_exit(void);
void	ft_free_array(char **arr);
void	ft_free_stack(t_stack *stack);
int		ft_check_sorted_stack(t_stack *stack);

#endif
