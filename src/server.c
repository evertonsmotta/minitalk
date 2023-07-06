/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:20:14 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/06 18:20:16 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	sigusr_handler(int signal)
{
	static int	bit_server;
	static char	c;

	if (signal == SIGUSR1)
	{
		c = c | (0x01 << bit_server);
		bit_server++;
	}
	else if (signal == SIGUSR2)
		bit_server++;
	if (bit_server == 8)
	{
		ft_printf("%c", c);
		bit_server = 0;
		c = 0;
	}
}

int	main(int ac, char *av[])
{
	(void) av;
	if (ac != 1)
	{
		ft_printf("Invalid start of server! Please run <./server> only");
		return (1);
	}
	ft_printf("Server PID: %i\n", getpid());
	ft_printf("Waiting messagem from client\n");
	while (ac == 1)
	{
		signal(SIGUSR1, sigusr_handler);
		signal(SIGUSR2, sigusr_handler);
	}
}
