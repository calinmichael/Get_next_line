/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:52:16 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/21 19:12:32 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*assign_head(t_list **head, t_list **tail, char *buffer)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		return (NULL);
	}
	*head = new_node;
	*tail = new_node;
	new_node->next = NULL;
	new_node->c = buffer[0];
	return (*head);
}

void	*append(t_list **tail, int j, char *buffer)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(buffer);
		return (NULL);
	}
	(*tail)->next = new_node;
	new_node->c = buffer[j];
	new_node->next = NULL;
	*tail = (*tail)->next;
	return (*tail);
}

int	a_and_a(t_list **head, t_list **tail, char *buffer, int result)
{
	int		j;
	int		flag;

	j = 0;
	flag = 0;
	while (j < result)
	{
		if (buffer[j] == '\n')
			flag = 1;
		j++;
	}
	j = 0;
	if (*head == NULL)
	{
		*head = assign_head(head, tail, buffer);
		j++;
	}
	while (j < result)
	{
		append(tail, j, buffer);
		j++;
	}
	return (flag);
}

char	*main_loop(int fd, char *buffer, t_list **head, t_list **tail)
{
	int		result;
	char	*res;
	int		flag;
	char	*str;

	flag = 0;
	while (flag != 1)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		res = check_res(result, head, tail, buffer);
		if (result <= 0)
			return (res);
		flag = a_and_a(head, tail, buffer, result);
		str = create_line(head, tail, buffer);
		if (str)
			return (str);
	}
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	static t_list	*tail;
	char			*str;
	char			*buffer;
	int				test;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	if (head)
	{
		str = create_line(&head, &tail, buffer);
		if (str)
			return (str);
	}
	str = main_loop(fd, buffer, &head, &tail);
	return (str);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc < 2)
	{
		printf("No file provided. Reading from standard input.\n");
		fd = 0; // Read from standard input if no file is provided
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
	}
	printf("Every time you press enter, you get a line from the file \n\n");
	line = malloc(1);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (fd)
			getchar();
		printf("%s", line);
	}
}*/