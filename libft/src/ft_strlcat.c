/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:48:43 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/09 20:07:50 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	len = dest_len;
	i = 0;
	if (dest_len < n - 1 && n > 0)
	{
		while (src[i] && dest_len + i < n - 1)
		{
			dest[len] = src[i];
			len++;
			i++;
		}
		dest[len] = '\0';
	}
	if (dest_len >= n)
		dest_len = n;
	return (src_len + dest_len);
}
