/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:04:13 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/25 15:08:07 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printk(const char *format, va_list args, int i, int	*len)
{
	char	x;

	if (format[i] == 'c')
	{
		x = va_arg(args, int);
		*len += write(1, &x, 1);
	}
	if (format[i] == '%')
		*len += write(1, "%", 1);
	if (format[i] == 'd' || format[i] == 'i')
		print_num(args, len);
	if (format[i] == 's')
		print_str(args, len);
	if (format[i] == 'u')
		print_unum(args, len);
	if (format[i] == 'x' || format[i] == 'X')
		print_hexa_num(args, len, format[i]);
	if (format[i] == 'p')
		print_address(args, len);
}

int	ft_printf(const	char *format, ...)
{
	va_list	args;
	int		printed_char;
	int		*len;
	int		i;

	va_start(args, format);
	i = 0;
	printed_char = 0;
	len = &printed_char;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_printk(format, args, i, len);
		}
		else if (format[i] != '%')
			ft_putchar(format[i], len);
		i++;
	}
	va_end(args);
	return (printed_char);
}
