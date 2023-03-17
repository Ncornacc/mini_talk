/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:59:44 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/08 10:51:31 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*ptr;
	int			i;

	i = 0;
	while (s[i])
		i++;
	ptr = (char *)malloc(i + 1);
	if (s == (void *)0)
		return (0);
	if (!ptr)
		return (0);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
