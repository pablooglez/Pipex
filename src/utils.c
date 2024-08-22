/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:21:00 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/22 17:23:31 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **split)
{
	int	i;
	
	i = 0;

	if (split == NULL)
	{
		return;
	}
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}