/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:19:58 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/07 17:17:24 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (!n)
		return (len);
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n < len)
		dest[n - 1] = '\0';
	else if (n != 0)
		dest[i] = '\0';
	return (len);
}
