/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:28:53 by ccambium          #+#    #+#             */
/*   Updated: 2021/11/24 18:26:16 by ccambium         ###   ########.fr       */
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

	while (*(junk + i) != 0)
	{
		i++;
		if (*(junk + i) == '\n')
			return (1);
	}
	return (0);
}

char	*remove_from_junk(char *junk, size_t size)
{
	size_t	new_size;
	char	*new_junk;

	new_size = ft_strlen(junk) - size;
	new_junk = malloc(new_size + 1);
	if (new_junk == NULL)
		return (NULL);
	strlcpy(new_junk, junk + size, new_size);
	free(junk);
	return (new_junk);
}
