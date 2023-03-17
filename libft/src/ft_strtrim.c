/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 12:47:22 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/08 13:26:02 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(char c, const char *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	ptr = NULL;
	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_check(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_check(s1[end - 1], set))
		end--;
	ptr = ft_substr(s1, start, end - start);
	return (ptr);
}
