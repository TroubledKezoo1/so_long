/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <ysarac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 04:10:38 by ysarac            #+#    #+#             */
/*   Updated: 2024/03/08 14:30:43 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minilibx/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	game_end(t_so_long *s)
{
	ft_malloc_error(s->map);
	if (s->background)
		mlx_destroy_image(s->mlx_ptr, s->background);
	if (s->coin)
		mlx_destroy_image(s->mlx_ptr, s->coin);
	if (s->door)
		mlx_destroy_image(s->mlx_ptr, s->door);
	if (s->playerimg)
		mlx_destroy_image(s->mlx_ptr, s->playerimg);
	if (s->wall)
		mlx_destroy_image(s->mlx_ptr, s->wall);
	if (s->mlx_win)
		mlx_destroy_window(s->mlx_ptr, s->mlx_win);
	exit(0);
}

void	free_map(t_so_long *s)
{
	ft_malloc_error(s->map);
	exit(0);
}

char	**ft_malloc_error(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	free_newline(char *str)
{
	if (*str)
		free(str);
	exit(0);
}
