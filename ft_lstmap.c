/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:26:52 by msisto            #+#    #+#             */
/*   Updated: 2024/01/29 15:59:28 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		res = ft_lstnew(lst -> content);
		lst = lst -> next;
	}
	ft_lstiter(res, (*f)(res -> content));
	if (!res)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	ft_lstadd_back(&new, res);
	return (new);
}
