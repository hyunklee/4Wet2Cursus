/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunklee <hyunklee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:47:51 by hyunklee          #+#    #+#             */
/*   Updated: 2021/05/20 18:37:13 by hyunklee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst->content);
	if (!(ret = ft_lstnew(new)))
		return (0);
	lst = lst->next;
	while (lst)
	{
		new = f(lst->content);
		if (!new)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, ft_lstnew(new));
		lst = lst->next;
	}
	return (ret);
}
