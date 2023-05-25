/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:03:24 by iobba             #+#    #+#             */
/*   Updated: 2022/12/29 14:04:40 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	errrrore(char *str, int i)
{
	write(2, "pipex: ", 7);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	if (i)
	{
		while (wait(NULL) != -1)
			;
	}
	exit(EXIT_FAILURE);
}

void	no_command(char **arg)
{
	write(2, "pipex: ", 7);
	write(2, arg[0], ft_strlen(arg[0]));
	write(2, ": command not found\n", 20);
	freeing(arg);
	exit (127);
}

void	no_file(char **arg)
{
	write(2, "pipex: ", 7);
	write(2, arg[0], ft_strlen(arg[0]));
	write(2, " : no such file or directory\n", 29);
	freeing(arg);
	exit (127);
}
