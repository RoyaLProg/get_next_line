/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:58 by ccambium          #+#    #+#             */
/*   Updated: 2021/12/14 17:48:24 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_to_junk(char *tmp, char *junk)
{
	char	*njunk;

	if (!is_junk_empty(junk))
	{
		njunk = malloc(BUFFER_SIZE + 1 + ft_strlen(junk));
		if (njunk == NULL)
		{
			free(junk);
			return (NULL);
		}
		ft_strlcpy(njunk, junk, ft_strlen(junk) + 1);
		ft_strlcat(njunk, tmp, BUFFER_SIZE + ft_strlen(junk) + 1);
	}
	else
	{
		njunk = malloc(BUFFER_SIZE + 1);
		if (njunk == NULL)
		{
			free(junk);
			return (NULL);
		}
		ft_strlcpy(njunk, tmp, BUFFER_SIZE + 1);
	}
	free(junk);
	return (njunk);
}

char	*get_line_from_junk(char *junk)
{
	char	*v;
	size_t	i;
	size_t	size;

	i = 0;
	if (junk[0] == 0)
		return (NULL);
	while (*(junk + i) != '\n' && *(junk + i))
		i++;
	size = i + 1;
	v = malloc(size + 1);
	if (v == NULL)
		return (NULL);
	ft_strlcpy(v, junk, size + 1);
	return (v);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(src + i) != 0 && i < size - 1 && size != 0)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (size != 0)
		*(dst + i) = 0;
	while (*(src + i) != 0)
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	char		*v;
	static char	*junk;
	ssize_t		r;

	while (!is_line_in_junk(junk))
	{
		v = malloc(BUFFER_SIZE + 1);
		if (v == NULL)
			return (NULL);
		ft_bzero(v, BUFFER_SIZE + 1);
		r = read(fd, v, BUFFER_SIZE);
		if (!r || r == -1)
		{
			free(v);
			v = NULL;
			if (!is_junk_empty(junk))
				v = get_line_from_junk(junk);
			free(junk);
			junk = NULL;
			return (v);
		}
		junk = move_to_junk(v, junk);
		free(v);
	}
	v = get_line_from_junk(junk);
	junk = remove_line_from_junk(junk);
	return (v);
}
