/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_second_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <ysarac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 05:44:41 by ysarac            #+#    #+#             */
/*   Updated: 2024/03/08 14:30:37 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "so_long.h"

static void	explore_map(char **map, t_control *control, int y, int x)
{
	if (x == -1 || y == -1 || !map[y] || !map[y][x] || map[y][x] == '#'
		|| map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		control->exit_accesible = 1;
	else if (map[y][x] == 'C')
		control->coin_accesible++;
	map[y][x] = '#';
	explore_map(map, control, y + 1, x);
	explore_map(map, control, y - 1, x);
	explore_map(map, control, y, x + 1);
	explore_map(map, control, y, x - 1);
}

void	maps_path_control(t_so_long *s, char **map)
{
	t_control	control;

	control.exit_accesible = 0;
	control.coin_accesible = 0;
	explore_map(map, &control, s->player_y, s->player_x);
	ft_malloc_error(map);
	if (!control.exit_accesible)
	{
		ft_malloc_error(s->map);
		ft_printf("Errorn");
		exit(1);
	}
	if (control.coin_accesible != s->count_c)
	{
		ft_malloc_error(s->map);
		ft_printf("Error\n");
		exit(1);
	}
}

void	maps_wall_control2(t_so_long *data)
{
	int	y;
	int	x;

	y = data->map_height;
	x = data->map_width;
	while (y--)
		if (x != (int)ft_strlen(data->map[y]))
			return (ft_printf("Error\n"), free_map(data));
}

void	maps_newline_control(char **map, t_so_long *data, char *str)
{
	int	i;
	int	newline_counter;

	i = 0;
	newline_counter = 0;
	data->map_width = ft_strlen(map[i]);
	while (map[i])
	{
		data->map_height++;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			newline_counter++;
		i++;
	}
	if (newline_counter > data->map_height - 1)
	{
		return (ft_printf("Error"), free_map(data), free_newline(str));
	}
}
