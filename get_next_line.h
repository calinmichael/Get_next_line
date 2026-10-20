/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:55:05 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/20 16:54:41 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			c;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	del(t_list **head, t_list **tail, int line_len, char *str);
char	*stop_it(t_list **head, t_list **tail, char *buffer, int line_len);
char	*create_line(t_list **head, t_list **tail, char *buffer);
char	*get_remaining(t_list **head, t_list **tail, char *buffer);
char	*check_res(int result, t_list **head, t_list **tail, char *buffer);
t_list	*assign_head(t_list **head, t_list **tail, char *buffer);
void	*append(t_list **tail, int j, char *buffer);
int		find_flag(int result, char *buffer);
int		a_and_a(t_list **head, t_list **tail, char *buffer, int result);
char	*main_loop(int fd, char *buffer, t_list **head, t_list **tail);
#endif
