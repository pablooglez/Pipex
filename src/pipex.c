/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:12:18 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/22 20:19:06 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_first_child(char **argv, int *fd, char **env)
{
	int	infile;
	
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	if (dup2(fd[1], STDOUT_FILENO == -1))
	{
		ft_error_pipex("Dup2 Error");
	}
	close (fd[1]);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		ft_error_pipex("Infile Error");
	}
	dup2(infile, STDIN_FILENO);
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		ft_error_pipex("Dup2 Error");
	}
	close(infile);
	execve (ft_get_cmd_path(argv, ft_get_path(env)), ft_split(argv[2], ' '), env);
	ft_error_pipex("Error execve");
	exit (1);
}

void	process_second_child(char **argv, int *fd, char **env)
{
	int	outfile;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		ft_error_pipex("Dup2 Error");
	}
	close(fd[0]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		ft_error_pipex("Outfile error");
	}
	dup2(outfile, STDOUT_FILENO);
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		ft_error_pipex("Dup2 Error");
	}
	close(outfile);
	execve (ft_get_cmd_path(argv, ft_get_path(env)), ft_split(argv[3], ' '), env);
	ft_error_pipex("Error execve");
	exit(1);
}

void	execute_program(char **argv, int *fd, char **env)
{
	pid_t	pid;
	pid_t	pid2;

	pid = fork();

	if (pid == -1)
	{
		ft_error_pipex("Fork Error");
	}
	
	if (pid == 0)
	{
		//Process First Child
		process_first_child(argv, fd, env);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
		{
			ft_error_pipex("Fork Error");
		}
		
		if (pid2 == 0)
		{
			//Process Second Child
			process_second_child(argv, fd, env);
		}
		else
		{
			//Procces Father
			close(fd[0]);
			close(fd[1]);
		}
		
	}
}