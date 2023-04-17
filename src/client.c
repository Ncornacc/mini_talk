/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 14:45:29 by ncornacc      #+#    #+#                 */
/*   Updated: 2023/03/16 14:45:30 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	END = 0;

void	got_signal(int sig)
{
	if (sig == SIGUSR1)
		END = 1;
}

void	ft_send_bits(int pid, char i)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (1)
		{
			if (END == 1)
				break ;
		}
		END = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGUSR1, got_signal);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}