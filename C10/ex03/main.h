/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mojo <mojo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:13:51 by mojo              #+#    #+#             */
/*   Updated: 2022/02/16 08:28:44 by mojo             ###   ########.fr       */
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

typedef struct s_info
{
	char	cur[16];
	char	before[16];
	int		star_op;
	int		option;
}				t_info;

void			print_address_o(unsigned int address, int fin);
void			print_hex_o(char *s, int size);
void			print_string_o(char *s, int size);
void			print_blank_o(int idx);
void			print_memory_o(char *s, unsigned int size, int how);
void			print_address_x(unsigned int address, int fin);
void			print_hex_x(char *s, int size);
void			print_blank_x(int idx);
void			print_memory_x(char *s, unsigned int size, int how);
void			print_remainder(t_info *t, unsigned int length);
unsigned int	go_other(int fd, unsigned int length, t_info *t);
void			error_message(char *exec_name, char *s);
void			bad_file(char *exec_name, char *s);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
void			operation(t_info *t, unsigned int length);
int				str_len(char *s);

#endif
