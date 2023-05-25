/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iobba <iobba@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 10:27:29 by iobba             #+#    #+#             */
/*   Updated: 2022/12/29 14:48:17 by iobba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strchr(const char *str, int c);
char	*get_lo_path(char **env, char *cmd);
void	errrrore(char *str, int i);
void	no_command(char **arg);
void	no_file(char **arg);
void	freeing(char **str);
int		make_here_doc(char *limiter);
int		get_fd_in(char **av, int x);
int		get_fd_out(char *outfile, int x);
int		min_argc(char *av1);
char	*get_next_line(int fd);
int		ft_strncmp(const char *ms1, const char *ms2, size_t n);
char	**ft_split(char const *str, char c);

#endif
