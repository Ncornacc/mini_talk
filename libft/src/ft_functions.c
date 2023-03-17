/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_functions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 15:46:12 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/17 14:12:33 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	print_num(va_list args, int *len)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr(num, len);
}

void	print_str(va_list args, int *len)
{
	char	*ptr;

	ptr = va_arg(args, char *);
	if (!ptr)
		ft_putstr("(null)", len);
	else
		ft_putstr(ptr, len);
}

void	print_unum(va_list args, int *len)
{
	unsigned int	num;

	num = va_arg(args, int);
	ft_putnbr_u(num, len);
}

void	print_address(va_list args, int *len)
{
	unsigned long	address;

	address = va_arg(args, unsigned long);
	if ((void *)address == 0)
		ft_putstr("0x0", len);
	else
	{
		ft_putstr("0x", len);
		ft_putnbr_ul(address, "0123456789abcdef", len);
	}
}

void	print_hexa_num(va_list args, int *len, char c)
{
	unsigned long	num;

	num = va_arg(args, unsigned long);
	if (c == 'X')
		ft_putnbr_base(num, "0123456789ABCDEF", len);
	else
		ft_putnbr_base(num, "0123456789abcdef", len);
}
