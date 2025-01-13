/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:55:54 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/13 15:24:10 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exits;
	int		players;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
}			t_game;

//// validate_map.c ////
int			is_rectangular(t_map *map);
int			is_surrounded_by_walls(t_map *map);
int			is_enough_elements(t_map *map);
int			count_exits_collects(char **map, int x, int y, t_map *m);
int			validate_path(t_map *map);

/// ft_function///
char		**ft_array_dup(char **array);
void		ft_array_free(char **array);
int			ft_error(char *message);

#endif