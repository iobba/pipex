/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:24:53 by iobba             #+#    #+#             */
/*   Updated: 2022/12/30 11:33:25 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_path(char **env, char *cmd)
{
	char		*line_of_path;
	char		**arr;
	static int	j;
	char		*filename;
	char		*with_slash;

	line_of_path = get_lo_path(env, cmd);
	arr = ft_split(line_of_path + 5, ':');
	while (arr[j])
	{
		with_slash = ft_strjoin(arr[j++], "/");
		filename = ft_strjoin(with_slash, cmd);
		free(with_slash);
		if (access(filename, F_OK) == 0)
		{
			freeing(arr);
			return (filename);
		}
		free(filename);
	}
	return (freeing(arr), NULL);
}

void	child_proccess(char *cmd, char **env, int pi_1, int pi_0)
{
	char	**arg;
	char	*filename;

	dup2(pi_0, 0);
	dup2(pi_1, 1);
	close(pi_0);
	close(pi_1);
	arg = ft_split(cmd, ' ');
	if (ft_strchr(arg[0], '/') && !access(arg[0], F_OK))
		filename = arg[0];
	else if (ft_strchr(arg[0], '/') && access(arg[0], F_OK))
		no_file(arg);
	else
	{
		filename = get_path(env, arg[0]);
		if (!filename)
			no_command(arg);
	}
	if (execve(filename, arg, env) == -1)
		errrrore(": execve", 0);
}

int	forking(char *cmd, char **env, int pi_0, int fd_out)
{
	int		fd[2];
	pid_t	id;
	int		pi_1;

	if (pipe(fd) == -1)
		errrrore(": pipe", 0);
	id = fork();
	if (id < 0)
		errrrore(": fork", 0);
	if (id)
	{
		close(pi_0);
		close(fd[1]);
		return (fd[0]);
	}
	if (!fd_out)
		pi_1 = fd[1];
	else
		pi_1 = fd_out;
	close(fd[0]);
	child_proccess(cmd, env, pi_1, pi_0);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int			fd_in;
	int			fd_out;
	int			x;
	static int	i;

	x = min_argc(av[1]) - 5;
	if (ac < min_argc(av[1]))
		errrrore (": arguments", 0);
	fd_in = get_fd_in(av, x);
	fd_out = get_fd_out(av[ac - 1], x);
	while (i < ac - 3 - x)
	{
		if (i == ac - 3 - x - 1)
		{
			if (fd_out == -1)
				errrrore(": outfile", 1);
			fd_in = forking(av[i + x + 2], env, fd_in, fd_out);
		}
		else
			fd_in = forking(av[i + x + 2], env, fd_in, 0);
		i++;
	}
	while (wait(NULL) != -1)
		;
	return (0);
}
