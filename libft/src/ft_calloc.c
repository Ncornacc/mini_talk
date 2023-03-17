/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:09:07 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/07 18:14:57 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;
	int		bytes_s;

	i = 0;
	bytes_s = nmemb * size;
	ptr = malloc(bytes_s);
	if (ptr == NULL)
		return (0);
	while (bytes_s > 0)
	{
		ptr[i] = '\0';
		i++;
		bytes_s--;
	}
	return ((void *)ptr);
}
