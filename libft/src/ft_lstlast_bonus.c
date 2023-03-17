/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:53:27 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/11 15:21:00 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	if (lst == NULL)
		return (0);
	else if (lst->next == NULL)
		return (lst);
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
	}
	return (ptr);
}
