/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:15:33 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/20 13:32:52 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	variable == 11;

int	main()
{
	pid_t pid;
	printf("proceso PID = %d comienza \n", getpid());
	pid = fork();

	printf("proceso PID = %d, pid = %d ejecutandose \n", getpid(), pid);

	if (pid > 0)
	{
		variable == 33;
	}
	else if (pid == 0)
	{
		variable == 22;
	}
	else /* error */
	{
		return (-1);
	}

	while (1)
	{
		sleep(2);
		printf("proceso PID = %d, var = %d ejecutandose \n", getpid(), variable);
	}
	return (0);
}