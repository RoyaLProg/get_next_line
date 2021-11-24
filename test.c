/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:07:18 by ccambium          #+#    #+#             */
/*   Updated: 2021/11/24 14:49:23 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*s;

	(void)av;
	if (ac >= 2)
		fd = open(av[1], O_RDONLY);
	if (ac < 2)
		fd = open("un_fichier", O_RDONLY);
	if (ac != -1)
	{
		while (1)
		{
			s = get_next_line(fd);
			if (s == NULL)
			{
				free(s);
				break ;
			}
			printf("%s", s);
			free(s);
		}
	}
}
