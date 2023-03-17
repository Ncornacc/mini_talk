/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printfunc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 15:52:59 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/18 14:14:13 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	num;

	num = 0;
	if (n < 0)
	{
		ft_putchar('-', len);
		num = -n;
	}
	else
		num = n;
	if (num > 9)
	{
		ft_putnbr(num / 10, len);
		num %= 10;
	}
	ft_putchar(num + '0', len);
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void	ft_putnbr_u(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
		n %= 10;
	}
	ft_putchar(n + '0', len);
}

void	ft_putnbr_ul(unsigned long num, char *s, int *len)
{
	unsigned long	base_len;

	base_len = 0;
	while (s[base_len])
		base_len++;
	if (num > base_len - 1)
	{
		ft_putnbr_ul(num / base_len, s, len);
		num %= base_len;
	}
	ft_putchar(s[num], len);
}
