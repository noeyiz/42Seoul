/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:31:14 by jikoo             #+#    #+#             */
/*   Updated: 2022/12/19 21:36:11 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
/* libft */
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_circle_linked_list
{
	int		cur_size;
	int		max_size;
	t_node	*top;
}	t_stack;

int		ft_print_error(int type);

/* args */
void	ft_trim_args(int argc, char **argv, char ***args);
void	ft_verify_args(char **args);

/* utils */
void	ft_free_array(char **arr);

#endif
