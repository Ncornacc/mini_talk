/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:46:23 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/07 08:50:54 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == (char) c)
		return ((char *)s + i);
	return (0);
}
