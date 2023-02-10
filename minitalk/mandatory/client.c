/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:43:07 by maricard          #+#    #+#             */
/*   Updated: 2023/02/10 09:34:02 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	send_signal(int pid, char *str)
{
	int	i;
	int	c;

	while (*str)
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

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Client must receive 2 parameters: <PID> & <STRING>.\n");
		ft_printf("Example: '12345' 'Hello :)'\n");
		ft_printf("Please try doing this task right.\n");
	}
	else
		send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
