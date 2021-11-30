/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:32:58 by ccambium          #+#    #+#             */
/*   Updated: 2021/11/29 17:57:18 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_to_junk(char *tmp, char *junk)
{
	char	*njunk;

	if (!is_junk_empty(junk))
	{
		njunk = malloc(ft_strlen(tmp) + 1 + ft_strlen(junk));
		ft_strlcpy(njunk, junk, ft_strlen(junk));
		ft_strlcat(njunk, tmp, ft_strlen(tmp) + ft_strlen(junk));
	}
	else
	{
		njunk = malloc(BUFFER_SIZE + 1);
		ft_strlcpy(njunk, tmp, ft_strlen(tmp));
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
	while (*(junk + i) != 0 || *(junk + i) != '\n')
		i++;
	size = i;
	v = malloc(size + 1);
	if (v == NULL)
		return (NULL);
	ft_strlcpy(v, junk, size + 1);
	junk = remove_from_junk(junk, i);
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

char	*get_next_line(int fd)
{
	static char	*v;
	static char	*junk;
	char		*tmp;

	junk = 0;
	while (!is_line_in_junk(junk))
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (tmp == NULL)
			return (NULL);
		if (!read(fd, tmp, BUFFER_SIZE))
			return (junk);
		tmp[BUFFER_SIZE] = 0;
		junk = move_to_junk(tmp, junk);
		free(tmp);
	}
	v = get_line_from_junk(junk);
	return (v);
}
