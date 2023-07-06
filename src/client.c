/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:09:19 by eschirni          #+#    #+#             */
/*   Updated: 2023/07/05 11:22:54 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int server_pid, int c)
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

int	main(int ac, char *av[])
{
	int	server_pid;
	int	i;

	if (ac != 3)
	{
		printf("./client <server_pid>  <message to write in server>\n");
		return (1);
	}
	else
	{
		i = -1;
		server_pid = atoi(av[1]);
		while (av[2][++i])
			send_bits(server_pid, av[2][i]);
		send_bits(server_pid, '\n');
	}
}