#include "so_long.h"
#include "minilibx/mlx.h"
#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"

void	steps(t_so_long *ptr)
{
	char	*steps;
	char	*tmp;

	tmp = ft_itoa(ptr->count_step);
	steps = ft_strjoin("Steps: ", tmp);
	mlx_string_put(ptr->mlx_ptr,
		ptr->mlx_win, 10, 30, 0x00FFFFFF, steps);
	free(steps);
	free(tmp);
}

void	timer(t_so_long *s)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	s->cointimer++;
	if (s->cointimer <= 15)
		s->coin = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/coin.xpm", &a, &b);
	else if (s->cointimer <= 30)
		s->coin = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/coin1.xpm", &a, &b);
	else if (s->cointimer <= 45)
		s->coin = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/coin2.xpm", &a, &b);
	else
		s->cointimer = 0;
	if (!s->coin)
		game_end(s);
}

int	enemy_anger(t_so_long *game)
{
	timer(game);
	game->adrenaline++;
	if (game->adrenaline == 10)
		game->adrenaline = 0;
	else
		return (0);
	if (game->map[game->enemy_y][game->enemy_x - 1] == '1')
		game->wallcheck = 0;
	if (game->map[game->enemy_y][game->enemy_x + 1] == '1')
		game->wallcheck = 1;
	if (game->wallcheck && game->map[game->enemy_y][game->enemy_x - 1] != '1')
		game->enemy_x--;
	else if (!game->wallcheck
		&& game->map[game->enemy_y][game->enemy_x + 1] != '1')
		game->enemy_x++;
	return (1);
}

int	enemymovement(t_so_long *data)
{
	open_win(data, -1, -1);
	steps(data);
	if (data->player_x == data->enemy_x && data->player_y == data->enemy_y)
	{
		ft_printf("Game Over!!");
		game_end(data);
	}
	if (!enemy_anger(data))
		return (0);
	if (data->map[data->enemy_y][data->enemy_x] != 'C'
		&& data->map[data->enemy_y][data->enemy_x] != 'E')
		data->map[data->enemy_y][data->enemy_x] = 'N';
	return (0);
}
