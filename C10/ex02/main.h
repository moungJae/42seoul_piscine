/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:33:27 by mojo              #+#    #+#             */
/*   Updated: 2022/02/15 14:43:28 by mojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H

# define MAIN_H

# include <libgen.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

void	no_argument(char *size);
void	yes_argument(int argc, char **argv);
int		is_isspace(char c);
int		ft_atoi(char *str);
void	go_write(int fd);
void	go_tail(int word_cnt, int fd);
void	print_result(char *s, int idx, int op, int cnt);
int		str_len(char *s);
void	print_message(char *s);
void	error_message(char *file, char *exec_name);

#endif
