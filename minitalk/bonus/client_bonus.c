/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:43:07 by maricard          #+#    #+#             */
/*   Updated: 2023/02/13 08:33:31 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	send_signal(int pid, char *str)
{
	int		i;
	int		c;
	char	*final;

	final = str + ft_strlen(str);
	while (str <= final)
	{
		c = *str;
		i = 0;
		while (i < 8)
		{
			if (1 & (c >> i))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
			i++;
		}
		str++;
	}
}

void	server_signal(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("\n ✅ MESSAGE RECEIVED ✅ \n\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_handler = &server_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("\n   ❌ ❌ ❌   \n\n");
		ft_printf("Client must receive 2 parameters: <PID> & <STRING>.\n");
		ft_printf("Example: 90345 hello\n");
		ft_printf("Please try agian\n\n");
	}
	else
		send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
