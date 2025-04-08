/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusomec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:18:11 by dmusomec          #+#    #+#             */
/*   Updated: 2025/04/05 21:32:50 by dmusomec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_server
{
    int             bit_count;
    pid_t           client_pid;
    unsigned char   c;
}   t_server;

static void reset_state(t_server *s)
{
    s->bit_count = 0;
    s->c = 0;
    s->client_pid = 0;
}

static void sig_hand(int sig, siginfo_t *info, void *context)
{
    static t_server s;

    (void)context;
    if (s.client_pid && s.client_pid != info->si_pid)
        reset_state(&s);
    s.client_pid = info->si_pid;
    s.c |= (sig == SIGUSR2) << (7 - s.bit_count);
    s.bit_count++;
    if (s.bit_count == 8)
    {
        if (s.c == '\0')
            ft_putchar_fd('\n', STDOUT_FILENO);
        else
            ft_putchar_fd(s.c, STDOUT_FILENO);
        reset_state(&s);
    }
}

int main(void)
{
    struct sigaction sa;

    ft_printf("Server PID: %d\n", getpid());
    sa.sa_sigaction = sig_hand;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1
        || sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_putstr_fd("Error: sigaction\n", STDERR_FILENO);
        return (1);
    }
    while (1)
        pause();
    return (0);
}
