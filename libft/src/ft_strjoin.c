/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 12:20:59 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/13 17:53:45 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		len1;
	int		len2;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2 + 1;
	ptr = (char *)malloc(sizeof(char) * (total_len));
	if (!ptr)
		return (0);
	ft_memmove(ptr, s1, len1);
	ft_memmove((ptr + len1), s2, len2);
	ptr[total_len - 1] = '\0';
	return (ptr);
}
