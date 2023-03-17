/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:29:11 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/13 16:14:18 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*start;

	if (!lst || !f)
		return (0);
	ptr = ft_lstnew(f(lst->content));
	if (!ptr)
		return (0);
	start = ptr;
	lst = lst->next;
	while (lst)
	{
		ptr->next = ft_lstnew(f(lst->content));
		if (!ptr->next)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ptr = ptr->next;
		lst = lst->next;
	}
	ptr->next = NULL;
	return (start);
}
