/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 08:39:22 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/06 12:56:06 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*new_s1 != *new_s2)
			return (*new_s1 - *new_s2);
		n--;
		new_s1++;
		new_s2++;
	}
	return (0);
}
