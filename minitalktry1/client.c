/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:19:32 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/14 16:25:04 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	put_signal(int pid, char *str)
{
	int	i;
	int	c;

	i = 7;
	while (*str)
	{
		c = *(str);
		i = 7;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_atoi(argv[1]) <= 0)
		{
			ft_printf("Invalid PID.\n");
			exit(1);
		}
		put_signal(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_printf("Invalid arguments. Example: ./client [PID] [String]\n");
		exit(1);
	}
	return (0);
}
