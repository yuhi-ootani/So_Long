/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:53 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/12 18:21:06 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(char *file, t_map *map)
{
	int lines = count_lines(file);
	if (lines <= 0)
		return (ft_error("Map is empty!"));

	map->grid = read_map(file, lines);
	if (!map->grid)
		return (ft_error("Failed to read map"));

	map->height = lines;
	map->width = ft_strlen(map->grid[0]);

	validate_map(map);
	return (1);
}