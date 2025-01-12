/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:02:13 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/12 18:17:29 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (ft_error("Usage: ./so_long map.ber"));

	if (!parse_map(argv[1], &game.map))
		return (0);

	if (!init_graphics(&game))
		return (0);

	render_map(&game);

	mlx_loop(game.mlx);
	return (0);
}