/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 14:45:37 by ncornacc      #+#    #+#                 */
/*   Updated: 2023/03/16 14:45:40 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sighandler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[93mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\n \033[91mPID\033[0m \033[92m->\033[0m %d", pid);
	ft_printf("\n \033[93mWaiting:...\033[0m\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_sighandler);
		signal(SIGUSR2, ft_sighandler);
		pause ();
	}
	return (0);
}