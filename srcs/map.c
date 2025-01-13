/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:53 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/13 17:33:18 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(char *file)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;
	int		line_count;
	ssize_t	i;

	fd = open(file, O_RDONLY);
	line_count = 0;
	bytes_read = 1;
	while (!(fd < 0) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		i = -1;
		while ((i++) && (i < bytes_read))
		{
			if (line_count == INT_MAX && buffer[i] == '\n')
				return (-2);
			if (buffer[i] == '\n')
				line_count++;
		}
	}
	close(fd);
	if (fd < 0 || bytes_read < 0)
		return (-1);
	return (line_count);
}

char	**read_map(char *file, int lines)
{
	int		fd;
	char	**array;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!array)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	line = ft_get_next_line(fd);
	while (i < lines && line)
	{
		array[i] = line;
		i++;
		line = ft_get_next_line(fd);
	}
	array[i] = NULL;
	close(fd);
	return (array);
}

int	is_valid_map(t_map *map)
{
	if (!is_rectangular(map))
		return (ft_error("Map is not rectangular.\n"));
	if (!is_surrounded_by_walls(map))
		return (ft_error("Map is not surrounded by walls.\n"));
	if (!is_enough_elements(map))
		return (ft_error("Map elements are invalid.(0, 1, E=1, C>0, P=1)\n"));
	if (validate_path(map) != ((map->exits) + (map->collectibles)))
		return (ft_error("No valid path in the map.\n"));
	return (1);
}

int	parse_map(char *file, t_map *map)
{
	map->height = count_lines(file);
	if (map->height >= 0 && map->height <= 2)
		return (ft_error("Too small map!"));
	else if (map->height == -1)
		return (ft_error("Failed to open or read file"));
	map->width = 0;
	while (map->grid[0][map->width])
	{
		if (map->width == INT_MAX)
		{
			map->width = -2;
			break ;
		}
		map->width++;
	}
	if (map->height == -2 || map->width == -2)
		return (ft_error("Map is too big!"));
	map->grid = read_map(file, map->height);
	if (!map->grid)
		return (ft_error("Failed to read map"));
	if (!is_valid_map(map))
	{
		ft_array_free(map->grid);
	}
	return (1);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>



// void test_validate_map(void)
// {
//     t_map valid_map = {
//         .grid = (char *[]){"11111", "1P0C1", "", "1C0E1", "11111", NULL},
//         .width = 5,
//         .height = 5,
//         .collectibles = 0,
//         .exits = 0,
//         .players = 0
//     };
//     t_map non_rectangular_map = {
//         .grid = (char *[]){"11111", "1P0C1", "10001", "1C0E", "11111", NULL},
//         .width = 5,
//         .height = 5
//     };
//     t_map not_surrounded_by_walls = {
//         .grid = (char *[]){"11111", "1P0C1", "10001", "1C0E0", "11110", NULL},
//         .width = 5,
//         .height = 5
//     };
//     t_map missing_elements = {
//         .grid = (char *[]){"11111", "1P001", "10001", "10001", "11111", NULL},
//         .width = 5,
//         .height = 5
//     };
//     t_map no_valid_path = {
//         .grid = (char *[]){"11111", "1P001", "11101", "1C0E1", "11111", NULL},
//         .width = 5,
//         .height = 5
//     };

//     printf("=== Testing validate_map ===\n");

//     // Test case 1: Valid map
//     if (is_valid_map(&valid_map))
//     {
//         printf("Test 1 Passed: Valid map\n");
//     }
//     else
//     {
//         printf("Test 1 Failed: Valid map marked as invalid\n");
//     }

//     // Test case 2: Non-rectangular map
//     if (!is_valid_map(&non_rectangular_map))
//     {
//         printf("Test 2 Passed: Non-rectangular map correctly identified\n");
//     }
//     else
//     {
//         printf("Test 2 Failed: Non-rectangular map marked as valid\n");
//     }

//     // Test case 3: Map not surrounded by walls
//     if (!is_valid_map(&not_surrounded_by_walls))
//     {
//         printf("Test 3 Passed: Map not surrounded by walls correctly identified\n");
//     }
//     else
//     {
//         printf("Test 3 Failed: Map not surrounded by walls marked as valid\n");
//     }

//     // Test case 4: Missing required elements
//     if (!is_valid_map(&missing_elements))
//     {
//         printf("Test 4 Passed: Map with missing elements correctly identified\n");
//     }
//     else
//     {
//         printf("Test 4 Failed: Map with missing elements marked as valid\n");
//     }

//     // Test case 5: No valid path
//     if (!is_valid_map(&no_valid_path))
//     {
//         printf("Test 5 Passed: Map with no valid path correctly identified\n");
//     }
//     else
//     {
//         printf("Test 5 Failed: Map with no valid path marked as valid\n");
//     }
// }

// int main(void)
// {
//     test_validate_map();
//     return 0;
// }
