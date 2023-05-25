/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:18:08 by iobba             #+#    #+#             */
/*   Updated: 2022/12/29 13:24:08 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *ms1, const char *ms2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) ms1;
	s2 = (unsigned char *) ms2;
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	make_here_doc(char *limiter)
{
	int		fd;
	char	*line;

	fd = open("myhere_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		errrrore (": here_doc", 0);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			exit (EXIT_FAILURE);
		if (!ft_strncmp(line, limiter, ft_strlen(limiter) + 1))
			break ;
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	close(fd);
	fd = open("myhere_doc", O_RDONLY, 0644);
	if (fd < 0)
		errrrore (": here_doc", 0);
	return (fd);
}

int	get_fd_in(char **av, int x)
{
	int	fd;

	if (x)
		return (make_here_doc(av[2]));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		errrrore(": infile", 0);
	return (fd);
}

int	get_fd_out(char *outfile, int x)
{
	int	fd;

	if (x)
		fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	return (fd);
}

int	min_argc(char *av1)
{
	if (!ft_strncmp("here_doc", av1, 9))
		return (6);
	else
		return (5);
}
