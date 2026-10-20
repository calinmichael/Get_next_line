/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:57:04 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/20 16:44:56 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	del(t_list **head, t_list **tail, int line_len, char *str)
{
	t_list	*temp;
	t_list	*current;
	int		j;

	temp = *head;
	j = 0;
	while (j < line_len && temp)
	{
		str[j] = temp->c;
		current = temp;
		temp = temp->next;
		*head = temp;
		free(current);
		j++;
	}
	if (*head == NULL)
	{
		*tail = NULL;
	}
	str[j] = '\0';
}

char	*stop_it(t_list **head, t_list **tail, char *buffer, int line_len)
{
	char	*str;

	str = malloc(line_len + 1);
	if (!str)
	{
		free(buffer);
		return (0);
	}
	del(head, tail, line_len, str);
	free(buffer);
	return (str);
}

char	*create_line(t_list **head, t_list **tail, char *buffer)
{
	t_list	*temp;
	t_list	*stop;
	char	*str;
	int		line_len;

	line_len = 0;
	temp = *head;
	stop = NULL;
	str = NULL;
	while (temp)
	{
		if (temp->c == '\n')
		{
			stop = temp;
			line_len++;
			break ;
		}
		temp = temp->next;
		line_len++;
	}
	if (stop)
		str = stop_it(head, tail, buffer, line_len);
	return (str);
}

char	*get_remaining(t_list **head, t_list **tail, char *buffer)
{
	t_list	*temp;
	char	*remaining;
	int		count;

	count = 0;
	temp = *head;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	remaining = malloc(count + 1);
	if (!remaining)
	{
		free(buffer);
		return (0);
	}
	del(head, tail, count, remaining);
	return (remaining);
}

char	*check_res(int result, t_list **head, t_list **tail, char *buffer)
{
	char	*remaining;

	if (result == -1)
	{
		free(buffer);
		return (0);
	}
	else if (result == 0)
	{
		if (*head == NULL)
		{
			free(buffer);
			return (0);
		}
		else
		{
			remaining = get_remaining(head, tail, buffer);
			free(buffer);
			return (remaining);
		}
	}
	return (NULL);
}
