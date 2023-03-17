/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:59:39 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/07 17:01:41 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*new_dest;
	const char	*new_src;

	new_dest = (char *)dest;
	new_src = (const char *)src;
	if (dest == (void *)0 && src == (void *)0)
		return (0);
	if (new_src < new_dest)
	{
		new_src += n;
		new_dest += n;
		while (n-- > 0)
			*--new_dest = *--new_src;
	}
	else
	{
		while (n > 0)
		{
			*new_dest = *new_src;
			new_dest++;
			new_src++;
			n--;
		}
	}
	return (dest);
}
