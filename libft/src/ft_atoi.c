/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ncornacc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 09:51:00 by ncornacc      #+#    #+#                 */
/*   Updated: 2022/10/07 09:40:46 by ncornacc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	final_num;
	int	i;
	int	sign;

	final_num = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == ' ')
		i++;
	if (nptr[i] && nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
			final_num = (final_num * 10) + (nptr[i++] - '0');
	}
	else
		return (0);
	return (final_num * sign);
}
