/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <yunusemresarac@yaani.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:26:52 by ysarac            #+#    #+#             */
/*   Updated: 2023/10/25 02:59:57 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	i = 0;
	s1_ptr = (const unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1_ptr[i] == s2_ptr[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((int)(s1_ptr[i] - s2_ptr[i]));
}
