/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:14:48 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/06 17:32:14 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	g_l;

void	send_bits_to_clinte(int server_pid, int c)
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

void	send_message(int pid)
{
	char	*msg;
	int		i;

	i = -1;
	msg = "Sua mensagem foi recebida";
	while (msg[++i])
		send_bits_to_clinte(pid, msg[i]);
	send_bits_to_clinte(pid, '\n');
}

void	ft_getpid(char c)
{
	static int	pid_client;
	int			i;

	i = 0;
	if (pid_client == 0)
		write(1, "\n", 1);
	if (c >= 48 && c <= 57)
		pid_client = pid_client * 10 + (c - 48);
	else
		i = 1;
	if (i == 1)
	{
		send_message(pid_client);
		pid_client = 0;
		i = 0;
		g_l = 0;
	}
}

void	client_response(int signal)
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
		if (g_l == 0)
			write(1, &c, 1);
		if (c == '\0')
			g_l++;
		else if (g_l > 0)
			ft_getpid(c);
		bit_server = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	(void) av;
	if (ac != 1)
	{
		ft_printf("Invalid start of server! Please run <./server> only");
		return (1);
	}
	ft_printf("Server PID: %i\n", getpid());
	ft_printf("Waiting messagem from client\n");
	signal(SIGUSR1, client_response);
	signal(SIGUSR2, client_response);
	while (1)
	{
		signal(SIGUSR1, client_response);
		signal(SIGUSR2, client_response);
	}
}
