/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:49:06 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/22 20:18:44 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_cmd_path(char **argv, char **path)
{
	int			i;
	char	**cmd;
	char	*temp;
	char	*cmd_and_path;

	i = 0;
	cmd = ft_split(argv[2], ' ');

	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd_and_path = ft_strjoin(temp, cmd[0]);
		if (access(cmd_and_path, X_OK) == 0)
		{
			return(cmd_and_path);
		}
		if (temp)
		{
			free(temp);
			free (cmd_and_path);
		}
	}
	ft_free_split(cmd);
	return (cmd[0]);
}

char	**ft_get_path(char **env)
{
	int	i;
	char	*full_path;
	char	**path_splitted;

	i = 0;
	full_path = NULL;

	while (env[i] && !full_path)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			full_path = (env[i] + 5);
		}
		i++;
	}
	if (!full_path)
	{
		ft_error_pipex("Error PATH variable not found in env");
	}
	path_splitted = ft_split(full_path, ':');
	if (!path_splitted)
	{
		ft_error_pipex("Error to split PATH variable");
	}
	return (path_splitted);
	
}

/*char **cosas = ft_split(argv[3], ' ');
	char *cmd = "ruta del comando";
	//cmd = ft_find_path(char *str, char **path)
	char **arg = "cmd + flags"
	//arg = ft_get_arg(char *str) */