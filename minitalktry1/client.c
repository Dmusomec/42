/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:19:32 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/05 21:31:57 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

static void	send_char(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("Error: kill()\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("Error: kill()\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
		}
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("Usage: ./client [PID] [MESSAGE]\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		ft_putstr_fd("Error: Invalid PID\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (*argv[2])
		send_char(pid, *argv[2]++);
	send_char(pid, '\0');
	return (EXIT_SUCCESS);
}
