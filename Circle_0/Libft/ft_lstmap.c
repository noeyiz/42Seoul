/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:13:53 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/03 16:34:03 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cur;
	t_list	*nxt;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	cur = new;
	lst = lst->next;
	while (lst)
	{
		nxt = ft_lstnew(f(lst->content));
		if (!nxt)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		cur->next = nxt;
		cur = nxt;
		lst = lst->next;
	}
	return (new);
}
