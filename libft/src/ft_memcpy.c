/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:09:50 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/07 16:59:28 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*new_src;
	char	*new_dest;

	new_src = (char *)src;
	new_dest = (char *)dest;
	i = 0;
	if (dest == (void *)0 && src == (void *)0)
		return (0);
	while (n > 0)
	{
		new_dest[i] = new_src[i];
		i++;
		n--;
	}
	return (dest);
}
