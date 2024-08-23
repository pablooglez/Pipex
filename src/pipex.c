/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:12:18 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/23 13:37:08 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_first_child(char **argv, int *fd, char **env)
{
	int		infile;
	char	**path;
	char	*cmd;

	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error_pipex("Dup2 Error");
	close(fd[1]);
	close(fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error_pipex("Infile Error");
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error_pipex("Dup2 Error");
	close(infile);
	path = ft_get_path(env);
	if (!path)
		ft_error_pipex("Error getting path");
	cmd = ft_get_cmd_path(argv[2], path);
	ft_free_split(path);
	if (!cmd)
		ft_error_pipex("zsh: Command not found");
	if (execve (cmd, ft_split(argv[2], ' '), env) == -1)
	{
		free(cmd);
		ft_error_pipex("Execve Error");
	}
	free(cmd);
	exit(1);
}

void	process_second_child(char **argv, int *fd, char **env)
{
	int		outfile;
	char	**path;
	char	*cmd;

	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error_pipex("Dup2 Error");
	close(fd[0]);
	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error_pipex("Outfile error");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error_pipex("Dup2 Error");
	close(outfile);
	path = ft_get_path(env);
	if (!path)
		ft_error_pipex("Error getting path");
	cmd = ft_get_cmd_path(argv[3], path);
	ft_free_split(path);
	if (!cmd)
		ft_error_pipex("zsh: Command not found");
	if (execve (cmd, ft_split(argv[3], ' '), env) == -1)
	{
		free(cmd);
		ft_error_pipex("Execve Error");
	}
	free(cmd);
	exit(1);
}

void	execute_program(char **argv, int *fd, char **env)
{
	pid_t	pid;
	pid_t	pid2;

	pid = fork();
	if (pid == -1)
		ft_error_pipex("Fork Error");
	if (pid == 0)
		process_first_child(argv, fd, env);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			ft_error_pipex("Fork Error");
		if (pid2 == 0)
		{
			process_second_child(argv, fd, env);
		}
		close(fd[0]);
		close(fd[1]);
		waitpid(pid2, NULL, WUNTRACED);
	}
}
