/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccambium <ccambium@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:34:04 by ccambium          #+#    #+#             */
/*   Updated: 2021/11/24 14:49:15 by ccambium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

#endif
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
