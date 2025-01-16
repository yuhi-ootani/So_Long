/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:52:21 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/16 10:11:07 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_current_cell(int x, int y, t_game *game)
{
	if (game->map.grid[y][x] == '0' || game->map.grid[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map.grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	move_player(t_game *game, int dx, int dy)
{
	char	destination;
	int		new_x;
	int		new_y;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	destination = game->map.grid[new_y][new_x];
	if (destination == '1')
		return ;
	if (destination == 'E' && game->map.collectibles == 0)
		close_game(game);
	if (destination == 'C')
	{
		game->map.collectibles--;
		game->map.grid[new_y][new_x] = '0';
	}
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	update_current_cell(game->map.player_x, game->map.player_y, game);
	mlx_put_image_to_window(game->mlx, game->win, game->img_player, new_x
		* TILE_SIZE, new_y * TILE_SIZE);
	game->map.player_x = new_x;
	game->map.player_y = new_y;
}

int	handle_keypress(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, 0, -1);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, 0, 1);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, -1, 0);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}

// mlx_destroy_image releases the memory and resources associated with an image
// that you created with functions like mlx_xpm_file_to_image.
int	close_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map.grid)
		ft_array_free(game->map.grid);
	exit(0);
	return (0);
}
