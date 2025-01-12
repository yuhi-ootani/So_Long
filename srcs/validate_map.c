/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:34:13 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/12 19:34:43 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function prototypes
int	is_rectangular(t_map *map);
int	is_surrounded_by_walls(t_map *map);
int	count_elements(t_map *map);
int	is_valid_path(t_map *map);

int	validate_map(t_map *map)
{
	// Check if the map is rectangular
	if (!is_rectangular(map))
	{
		fprintf(stderr, "Error: Map is not rectangular.\n");
		return (0);
	}
	// Check if the map is surrounded by walls
	if (!is_surrounded_by_walls(map))
	{
		fprintf(stderr, "Error: Map is not surrounded by walls.\n");
		return (0);
	}
	// Count and validate the required elements
	if (!count_elements(map))
	{
		fprintf(stderr, "Error: Invalid number of required map elements.\n");
		return (0);
	}
	// Check if there is a valid path
	if (!is_valid_path(map))
	{
		fprintf(stderr, "Error: No valid path in the map.\n");
		return (0);
	}
	return (1); // Map is valid
}

// Check if the map is rectangular
int	is_rectangular(t_map *map)
{
	for (int i = 0; i < map->height; i++)
	{
		if ((int)strlen(map->grid[i]) != map->width)
		{
			return (0);
		}
	}
	return (1);
}

// Check if the map is surrounded by walls
int	is_surrounded_by_walls(t_map *map)
{
	// Check top and bottom rows
	for (int i = 0; i < map->width; i++)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
		{
			return (0);
		}
	}
	// Check left and right columns
	for (int i = 0; i < map->height; i++)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
		{
			return (0);
		}
	}
	return (1);
}

// Count required elements in the map
int	count_elements(t_map *map)
{
	char	c;

	map->collectibles = 0;
	map->exits = 0;
	map->players = 0;
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			c = map->grid[i][j];
			if (c == 'C')
			{
				map->collectibles++;
			}
			else if (c == 'E')
			{
				map->exits++;
			}
			else if (c == 'P')
			{
				map->players++;
			}
			else if (c != '0' && c != '1')
			{
				return (0); // Invalid character
			}
		}
	}
	// Validate element counts
	if (map->exits != 1 || map->players != 1 || map->collectibles < 1)
	{
		return (0);
	}
	return (1);
}

// Check if there is a valid path in the map using Flood Fill
int	flood_fill(char **grid, int x, int y, int height, int width)
{
	if (x < 0 || y < 0 || x >= height || y >= width || grid[x][y] == '1')
	{
		return (0);
	}
	if (grid[x][y] == 'E' || grid[x][y] == 'C')
	{
		grid[x][y] = '1'; // Mark as visited
		return (1);
	}
	if (grid[x][y] == '0' || grid[x][y] == 'P')
	{
		grid[x][y] = '1'; // Mark as visited
		// Recursively check adjacent cells
		flood_fill(grid, x + 1, y, height, width);
		flood_fill(grid, x - 1, y, height, width);
		flood_fill(grid, x, y + 1, height, width);
		flood_fill(grid, x, y - 1, height, width);
	}
	return (1);
}

int	is_valid_path(t_map *map)
{
	char	**copy;
	int		start_x;
	int		result;

	start_x = -1, start_y;
	// Duplicate the grid for flood fill
	copy = malloc(sizeof(char *) * map->height);
	if (!copy)
	{
		perror("Error allocating memory");
		return (0);
	}
	for (int i = 0; i < map->height; i++)
	{
		copy[i] = strdup(map->grid[i]);
		if (!copy[i])
		{
			perror("Error duplicating grid");
			for (int j = 0; j < i; j++)
			{
				free(copy[j]);
			}
			free(copy);
			return (0);
		}
	}
	// Find the player's starting position
	start_x = -1, start_y = -1;
	for (int i = 0; i < map->height; i++)
	{
		for (int j = 0; j < map->width; j++)
		{
			if (copy[i][j] == 'P')
			{
				start_x = i;
				start_y = j;
				break ;
			}
		}
		if (start_x != -1)
			break ;
	}
	// Perform flood fill from the player's starting position
	result = flood_fill(copy, start_x, start_y, map->height, map->width);
	// Free the duplicate grid
	for (int i = 0; i < map->height; i++)
	{
		free(copy[i]);
	}
	free(copy);
	return (result);
}
