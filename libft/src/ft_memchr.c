/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 08:19:11 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/20 20:43:17 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*find;

	ptr = (unsigned char *)s;
	find = (void *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return (find + i);
		i++;
	}
	return (0);
}
