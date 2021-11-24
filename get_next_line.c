/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:58 by ccambium          #+#    #+#             */
/*   Updated: 2021/11/24 18:39:19 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*v;
	static char	*junk;
	char		*tmp;

	tmp = malloc(BUFFER_SIZE + 1);
	read(fd, &tmp, BUFFER_SIZE);
	free(temp);
	return (v);
}

void	move_to_junk(char *tmp, char *junk)
{
	ft_strlcat(junk, tmp, ft_strlen(tmp));
}

void	reset_buffer(void *buff, size_t size)
{
	size_t	i;

	while (i < size)
	{
		*((char *)buff + i) = 0;
		i++;
	}
}

char	*get_line_from_junk(char *junk)
{
	char	*v;

	return (v);
}
