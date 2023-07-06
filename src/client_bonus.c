/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:14:28 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/06 18:33:05 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	g_x;

void	send_bits_to_server(int server_pid, int c)
{
	int	bit_client;

	bit_client = 0;
	while (bit_client < 8)
	{
		if ((c & (0x01 << bit_client)))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		bit_client++;
	}
}

void	server_response(int signal)
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
		if (c == '\n')
			g_x = 1;
		printf("\033[38;5;33m%c", c);
		bit_server = 0;
		c = 0;
	}
}

void	send_message(char	**av)
{
	char	*int_client_pid;
	int		server_pid;
	int		client_pid;
	int		i;

	client_pid = getpid();
	server_pid = atoi(av[1]);
	i = -1;
	while (av[2][++i])
		send_bits_to_server(server_pid, av[2][i]);
	send_bits_to_server(server_pid, '\0');
	int_client_pid = ft_itoa(client_pid);
	i = 0;
	while (int_client_pid[i])
		send_bits_to_server(server_pid, int_client_pid[i++]);
	send_bits_to_server(server_pid, 4);
	free(int_client_pid);
}

int	main(int ac, char **av)
{
	int	l;

	l = 0;
	signal(SIGUSR1, server_response);
	signal(SIGUSR2, server_response);
	if (ac != 3)
	{
		ft_printf("<./client> <PID-SERVER> <Mensagem>\n");
		return (1);
	}
	else if (ac == 3)
		send_message(av);
	while (!g_x && l < 1000000)
	{
		signal(SIGUSR1, server_response);
		signal(SIGUSR2, server_response);
		l++;
	}
}
