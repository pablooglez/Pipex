/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:21:00 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/23 13:57:18 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	operate_dup2(int fd_old, int fd_new)
{
	if (dup2(fd_old, fd_new) == -1)
	{
		ft_error_pipex("Dup2 Error");
	}
	close(fd_old);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
