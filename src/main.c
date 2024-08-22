/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:01:30 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/22 16:42:52 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env) 
{
	int	fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			ft_error_pipex("Error creating pipe");
		}
		else
		{
			execute_program(argv, fd, env);
		}
	}
	else
	{
		ft_error_pipex("Error with the number of arguments");
	}
	return (0);
}