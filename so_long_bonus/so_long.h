/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <ysarac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:55:57 by ysarac            #+#    #+#             */
/*   Updated: 2024/03/08 09:54:52 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define P 64

typedef struct s_so_long
{
	char	**map;
	int		map_width;
	int		map_height;
	int		count_p;
	int		count_c;
	int		count_e;
	int		count_step;
	int		count_n;
	int		enemy_x;
	int		enemy_y;
	int		adrenaline;
	int		wallcheck;
	int		cointimer;
	int		player_x;
	int		player_y;
	void	*mlx_win;
	void	*mlx_ptr;
	void	*playerimg;
	void	*enemyimg;
	void	*wall;
	void	*background;
	void	*coin;
	void	*door;
}			t_so_long;

typedef struct s_control
{
	int		exit_accesible;
	int		coin_accesible;
}			t_control;

void		maps_name_control(t_so_long *data, char *str);
void		maps_read_control(t_so_long *data, char *str);
void		maps_wall_control(t_so_long *data, int x, int y);
void		maps_wall_control2(t_so_long *data);
void		maps_player_control(t_so_long *data, int x, int y);
void		maps_path_control(t_so_long *data, char **str);
void		maps_split_control(t_so_long *data, char *str);
void		maps_object_control(t_so_long *data);

void		game_init_control(t_so_long *data);
void		player_movement(t_so_long *data, int x, int y);
void		charackter_show(t_so_long *data, char c);
void		game_over(int a, t_so_long *data);
int			movement(int key, t_so_long *data);
int			enemymovement(t_so_long *data);
void		open_win(t_so_long *data, int x, int y);
void		game_end(t_so_long *data);
void		free_map(t_so_long *data);
char		**ft_malloc_error(char **tab);
void		maps_newline_control(char **map, t_so_long *data, char *str);
void		free_newline(char *str);
void		steps(t_so_long *ptr);
void		timer(t_so_long *s);
int			enemy_anger(t_so_long *game);
#endif