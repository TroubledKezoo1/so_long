/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <ysarac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:20:48 by ysarac            #+#    #+#             */
/*   Updated: 2024/03/08 03:49:12 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char **rem, int new_line)
{
	char	*line;

	if (!*rem)
		return (NULL);
	if (new_line == 0)
	{
		if (*rem)
		{
			free(*rem);
			*rem = NULL;
		}
		return (NULL);
	}
	else if (new_line == 1)
	{
		line = ft_strdup(*rem);
		free(*rem);
		*rem = NULL;
		return (line);
	}
	return (NULL);
}
