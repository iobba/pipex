/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:56:35 by iobba             #+#    #+#             */
/*   Updated: 2022/12/29 14:46:17 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strchr(const char *str, int c);
char	*get_lo_path(char **env, char *cmd);
int		get_fd(char *av, int x);
void	errrrore(char *str, int i);
void	no_command(char **arg);
void	no_file(char **arg);
void	freeing(char **str);
char	**ft_split(char const *str, char c);

#endif
