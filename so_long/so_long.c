/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <ysarac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:55:45 by ysarac            #+#    #+#             */
/*   Updated: 2024/03/08 14:53:26 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "so_long.h"

void	maps_name_control(t_so_long *data, char *str)
{
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".ber", 4) == 0)
		maps_read_control(data, str);
	else
	{
		ft_printf("Error");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_so_long	data;

	data.count_c = 0;
	data.count_e = 0;
	data.count_p = 0;
	data.count_step = 0;
	if (ac == 2)
	{
		maps_name_control(&data, av[1]);
		game_init_control(&data);
	}
	else
		ft_printf("Error");
	return (0);
}
