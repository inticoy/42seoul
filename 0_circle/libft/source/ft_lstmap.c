/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:45:14 by gyoon             #+#    #+#             */
/*   Updated: 2022/11/04 22:54:09 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	const int	size = ft_lstsize(lst);
	t_list		*ret;
	t_list		*t;
	int			i;
	void		*temp;

	if (!lst)
		return (0);
	temp = del;
	i = 0;
	ret = ft_lstnew(f(lst->content));
	lst = lst->next;
	t = ret;
	while (i < size - 1)
	{
		t->next = ft_lstnew(f(lst->content));
		t = t->next;
		lst = lst->next;
		i++;
	}
	return (ret);
}
