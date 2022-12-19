/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:40:48 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/20 05:27:08 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* 제출 전에 꼭 지워 ~! */
# include <stdio.h>
/********************/
# include <stdlib.h>
# include <unistd.h>
/* libft */
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		cur_size;
	int		max_size;
	t_node	*tail;
}	t_stack;

/* utils */
int		ft_ps_error(int type);
void	ft_free_array(char **arr);
void	ft_free_stack(t_stack *stack);

/* args */
char	**ft_trim_args(int argc, char **argv);
void	ft_verify_args(char **args);

/* init stack */
void	ft_init_stack(t_stack **a, t_stack **b, char **args);

/* stack commands */
void	ft_push_front(t_stack *stack, t_node *new);
void	ft_push_back(t_stack *stack, t_node *new);
t_node	*ft_pop_front(t_stack *stack);
t_node	*ft_pop_back(t_stack *stack);

#endif
