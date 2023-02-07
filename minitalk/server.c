/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:41:15 by maricard          #+#    #+#             */
/*   Updated: 2023/02/07 12:29:24 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	handler(int signal, siginfo_t *signalinfo, void *context)
{
	static int	i = 0;
	static char	c = 0;

	(void)signalinfo;
	(void)context;
	if (signal == SIGUSR2)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("SERVER PROCESS ID | %d\n", getpid());

	struct sigaction	sa_newsignal;

	sa_newsignal.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa_newsignal, NULL);
	sigaction(SIGUSR2, &sa_newsignal, NULL);
	while (1)
		pause();
}
