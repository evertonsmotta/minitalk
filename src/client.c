/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:20:28 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/07/06 18:20:30 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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
