/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                      :+:    :+:         */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 13:35:33 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/17 14:12:05 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned int n, char *s, int *len)
{
	unsigned int	base_len;

	base_len = 0;
	while (s[base_len])
		base_len++;
	if (n > base_len - 1)
	{
		ft_putnbr_ul(n / base_len, s, len);
		n %= base_len;
	}
	ft_putchar(s[n], len);
}
