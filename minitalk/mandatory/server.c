/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:41:15 by maricard          #+#    #+#             */
/*   Updated: 2023/02/10 09:34:15 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	handler(int signal)
{
	static int	i = 0;
	static char	c = 0;

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
	struct sigaction	sa;

	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("SERVER PROCESS ID | %d\n", getpid());
	while (1)
		pause();
}
