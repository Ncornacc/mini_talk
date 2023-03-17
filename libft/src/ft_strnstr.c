/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 09:00:29 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/10 13:26:02 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	n_len;
	char	*ptr;

	i = 0;
	k = 0;
	n_len = ft_strlen(little);
	ptr = (char *)big;
	if (n_len == 0)
		return (ptr);
	while (ptr[i] && len > 0)
	{
		k = 0;
		while (ptr[i + k] && little[k] && ptr[i + k] == little[k]
			&& i + k < len)
			k++;
		if (k == n_len)
			return (ptr + i);
		i++;
	}
	return (0);
}
