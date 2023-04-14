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
#include <stdio.h>
#include "minitalk.h"

void	ft_sighandler(int signal, siginfo_t *info, void *value)
{
	static int				bit = 0;
	static unsigned long	i = 0;

	(void)value;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction    sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[93mTry: ./server\033[0m\n");
		return (0);
	}
	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_sighandler;
	ft_printf("\n \033[91mPID\033[0m \033[92m->\033[0m %d", pid);
	ft_printf("\n \033[93mWaiting:...\033[0m\n");
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
	while (argc == 1)
		pause ();
	return (0);
}