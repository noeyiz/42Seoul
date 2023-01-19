/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:24:09 by jikoo             #+#    #+#             */
/*   Updated: 2023/01/19 16:19:36 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define ERR 0
# define OK 1
# define KO 2

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

/* create_stack */
t_node	*ft_create_node(int data);
t_stack	*ft_create_stack(void);

/* init_stack */
void	ft_init_stack(t_info *info);

/* checker */
void    ft_run_checker(t_info *info);

/* utils */
int		ft_print_and_exit(int type);
void	ft_free_array(char **arr);
void	ft_free_stack(t_stack *stack);
int		ft_check_sorted_stack(t_stack *stack);

#endif