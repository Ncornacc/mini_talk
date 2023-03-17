/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 14:13:51 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/10 14:37:43 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

static	int	ft_len(int n, int sign)
{
	int	len;

	len = 1;
	if (sign == -1)
	{
		len++;
		n = n * sign;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;
	int		sign;

	sign = ft_sign(n);
	if (n <= -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_len(n, sign);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (sign == -1)
		n = n * sign;
	while (len > 0)
	{
		if (len == 1 && sign == -1)
		{
			ptr[len - 1] = '-';
			break ;
		}
		ptr[len-- - 1] = (n % 10) + 48;
		n = n / 10;
	}
	return (ptr);
}
