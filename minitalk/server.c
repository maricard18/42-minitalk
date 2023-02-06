/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:41:15 by maricard          #+#    #+#             */
/*   Updated: 2023/02/06 11:44:28 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	handler(int signal)
{
	static int	i;
	static char	c;

	if (signal == SIGUSR2)
		c = c << 1;
	else
		c = c << 0;
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
	struct	sigaction {
		void	(*sa_handler)(int);
	};
	sigaction.sa_handler = handler;
	ft_printf("SERVER PROCESS ID | %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &handler, NULL);
		sigaction(SIGUSR2, &handler, NULL);
	}
}
