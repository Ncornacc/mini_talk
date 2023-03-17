/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 16:36:21 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/08 16:46:48 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0 && n != -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((n * -1), fd);
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
