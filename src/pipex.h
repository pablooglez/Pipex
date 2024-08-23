/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablogon <pablogon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:46:44 by pablogon          #+#    #+#             */
/*   Updated: 2024/08/23 02:18:58 by pablogon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../Libft/libft.h"

//--------------------ERROR----------------------//
void	ft_error_pipex(char *msg);

//--------------------GET_PATH-------------------//
char	*ft_get_cmd_path(char *argv, char **path);
char	**ft_get_path(char **env);

//--------------------MAIN FUCTION--------------//
int main(int argc, char **argv, char **env);

//--------------------PIPEX---------------------//
void	process_first_child(char **argv, int *fd, char **env);
void	process_second_child(char **argv, int *fd, char **env);
void	execute_program(char **argv, int *fd, char **env);

//--------------------UTILS--------------------//
void	ft_free_split(char **split);

#endif
