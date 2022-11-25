/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:00:53 by jikoo             #+#    #+#             */
/*   Updated: 2022/07/26 14:28:06 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*nxt;

	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		ft_lstdelone(cur, del);
		cur = nxt;
	}
	*lst = NULL;
}
