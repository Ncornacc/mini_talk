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
	i = i << 1 | (signal == SIGUSR1);
		
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
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
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sa.sa_sigaction = ft_sighandler;
	sigemptyset(&sa.sa_mask);
	ft_printf("\n \033[91mPID\033[0m \033[92m->\033[0m %d", pid);
	ft_printf("\n \033[93mWaiting:...\033[0m\n");
	sigaction(SIGUSR1, &sa, 0);	
	sigaction(SIGUSR2, &sa, 0);
	while (1)
	{	
		sleep(1);
	}
		
	return (0);
}