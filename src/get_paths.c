/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:49:06 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/23 17:02:57 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_cmd_path(char *argv, char **path)
{
	int		i;
	char	**cmd;
	char	*temp;
	char	*cmd_and_path;

	i = 0;
	cmd = ft_split(argv, ' ');
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd_and_path = ft_strjoin(temp, cmd[0]);
		if (access(cmd_and_path, X_OK) == 0)
		{
			ft_free_split(cmd);
			return (cmd_and_path);
		}
		free(cmd_and_path);
		i++;
	}
	cmd_and_path = ft_strdup(cmd[0]);
	ft_free_split(cmd);
	return (cmd_and_path);
}

char	**ft_get_path(char **env)
{
	int		i;
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
