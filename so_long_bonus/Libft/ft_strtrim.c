/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <yunusemresarac@yaani.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:42:35 by ysarac            #+#    #+#             */
/*   Updated: 2023/10/24 21:21:38 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && is_in_set(s1[i], set) == 1)
	{
		i++;
	}
	while (j > i && is_in_set(s1[j - 1], set) == 1)
	{
		j--;
	}
	return (ft_substr(s1, i, (j - i)));
}
