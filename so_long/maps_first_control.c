/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_first_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <ysarac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:56:09 by ysarac            #+#    #+#             */
/*   Updated: 2024/03/08 14:59:29 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

void	maps_read_control(t_so_long *data, char *str)
{
	int		fd;
	char	*line;
	char	*tmp_map;
	char	*tmp_tmp_map;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\n"), exit(1));
	line = get_next_line(fd);
	if (!line || line[0] == '\n')
		return (ft_printf("Error\n"), close(fd), exit(1));
	tmp_map = ft_strdup("");
	while (line)
	{
		tmp_tmp_map = ft_strjoin(tmp_map, line);
		free(line);
		free(tmp_map);
		tmp_map = tmp_tmp_map;
		line = get_next_line(fd);
	}
	close(fd);
	maps_split_control(data, tmp_map);
}

void	maps_split_control(t_so_long *data, char *str)
{
	data->map = ft_split(str, '\n');
	if (!data->map)
		return (ft_printf("Error"), free(str), exit(1));
	maps_newline_control(data->map, data, str);
	maps_wall_control(data, 0, 0);
	maps_path_control(data, ft_split(str, '\n'));
	free(str);
}

void	maps_wall_control(t_so_long *data, int x, int y)
{
	while (data->map[y][x])
		if (data->map[y][x++] != '1')
			return (ft_printf("Error"), free_map(data));
	y++;
	x = data->map_width - 1;
	while (y < data->map_height - 1)
	{
		if (data->map[y][0] == '1' && data->map[y][x] == '1')
			y++;
		else
			return (ft_printf("Error"), free_map(data));
	}
	x = 0;
	while (data->map[y][x])
	{
		if (data->map[y][x] != '1')
			return (ft_printf("Error"), free_map(data));
		x++;
	}
	maps_wall_control2(data);
	maps_player_control(data, -1, -1);
}

void	maps_player_control(t_so_long *data, int x, int y)
{
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == '0'
				|| data->map[y][x] == 'C' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'P')
			{
				if (data->map[y][x] == 'P')
				{
					data->player_y = y;
					data->player_x = x;
					data->count_p++;
				}
				if (data->map[y][x] == 'C')
					data->count_c++;
				if (data->map[y][x] == 'E')
					data->count_e++;
			}
			else
				return (ft_printf("Error\n"), free_map(data));
		}
	}
	maps_object_control(data);
}

void	maps_object_control(t_so_long *data)
{
	if (data->count_p != 1 || data->count_c == 0 || data->count_e != 1)
		return (ft_printf("Error\n"), free_map(data));
}
