/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:28:47 by iobba             #+#    #+#             */
/*   Updated: 2022/12/24 10:33:16 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	char	k;
	int		i;

	k = (char) c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == k)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == k)
		return ((char *)&str[i]);
	return (0);
}

void	freeing(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!(*to_find))
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
			{
				return (&str[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*get_lo_path(char **env, char *cmd)
{
	char	*line_of_path;
	int		i;

	i = 0;
	while (env[i])
	{
		line_of_path = ft_strstr(env[i], "PATH=");
		if (line_of_path != NULL)
			return (line_of_path);
		i++;
	}
	write(2, "pipex: ", 7);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	exit (127);
}
