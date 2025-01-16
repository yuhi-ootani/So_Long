/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:02:13 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/16 10:02:29 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game, int x, int y, char tile)
{
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			tile = game->map.grid[y][x];
			if (tile == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (tile == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (tile == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

int	init_graphics(t_game *game, int width, int height)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("MLX initialization failed"));
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "So Long");
	if (!game->win)
		return (ft_error("Window creation failed"));
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&width, &height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&width, &height);
	if (!game->img_wall || !game->img_floor || !game->img_collectible
		|| !game->img_exit || !game->img_player)
		return (ft_error("Failed to load XPM file!"));
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.move_count = 0;
	if (argc != 2)
		return (ft_error("Usage: ./so_long map.ber"));
	if (!parse_map(argv[1], &game.map))
		return (0);
	if (!init_graphics(&game, game.map.width, game.map.height))
		return (0);
	render_map(&game, 0, 0, ' ');
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
// mlx_hook invokes the corresponding callback function you’ve registered,
// when an event occurs.
// int mlx_hook(void *win_ptr, int x_event, int x_mask,
//             int (*funct)(), void *param);
// x_event (int):
// Represents the type of event (e.g., key press, mouse click).
// 2: Key press
// 17: Window close
// (often corresponds to the user clicking the window's close button)

// x_mask:
// Represents the filter/mask for which events are enabled.
// Uses bitwise values like 1L << n to enable specific event types.
// KeyPressMask (1L << 0), // 1L = long integer 1
// DestroyNotify: Use 0 as no mask is needed.
