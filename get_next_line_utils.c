/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:28:53 by ccambium          #+#    #+#             */
/*   Updated: 2021/12/02 11:56:57 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_junk_empty(char *junk)
{
	return (junk == NULL || junk == 0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

int	is_line_in_junk(char *junk)
{
	size_t	i;

	i = 0;
	if (is_junk_empty(junk))
		return (0);
	while (junk[i] != 0)
	{
		if (junk[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*remove_line_from_junk(char *junk)
{
	size_t	new_size;
	char	*new_junk;
	size_t	size;

	size = 0;
	while (*(junk + size) != '\n' && *(junk + size))
		size++;
	new_size = ft_strlen(junk) - size + 1;
	new_junk = malloc(new_size + 1);
	if (new_junk == NULL)
	{
		free(junk);
		return (NULL);
	}
	ft_strlcpy(new_junk, junk + size + 1, new_size + 1);
	free(junk);
	return (new_junk);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(dst + i) != 0 && i < size && size != 0)
		i++;
	while (*(src + j) != 0 && i < size - 1 && size != 0)
	{
		*(dst + i) = *(src + j);
		*(dst + i + 1) = 0;
		i++;
		j++;
	}
	while (*(src + j) != 0)
	{
		j++;
		i++;
	}
	return (i);
}
