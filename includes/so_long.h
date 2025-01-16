/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:55:54 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/16 10:10:55 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player;
	int		move_count;
}			t_game;

/// ft_function///
char		**ft_array_dup(char **array);
void		ft_array_free(char **array);
int			ft_error(char *message);
int			ft_strlen_newline(char *str);

//// main ////
void		render_map(t_game *game, int x, int y, char tile);
int			init_graphics(t_game *game, int width, int height);

//// map_parse ////
int			count_lines(char *file);
char		**read_map(char *file, int lines);
int			is_valid_map(t_map *map);
int			parse_map(char *file, t_map *map);

//// map_validate ////
int			is_rectangular(t_map *map);
int			is_surrounded_by_walls(t_map *map);
int			is_enough_elements(t_map *map);
int			count_exits_collects(char **map, int x, int y, t_map *m);
int			validate_path(t_map *map);

//// movement ////
void		update_current_cell(int x, int y, t_game *game);
void		move_player(t_game *game, int dx, int dy);
int			handle_keypress(int key, t_game *game);
int			close_game(t_game *game);

#endif