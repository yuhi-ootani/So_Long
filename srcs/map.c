/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:17:53 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/12 19:21:10 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;
	int		line_count;
	ssize_t	i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line_count = 0;
	i = 0;
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				line_count++;
			i++;
		}
	}
	close(fd);
	if (bytes_read < 0)
		return (-1);
	return (count_lines);
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
	while (i < lines && (line = ft_get_next_line(fd)) != NULL)
	{
		array[i] = line;
		i++;
	}
	array[i] = NULL;
	close(fd);
	return (array);
}

int	parse_map(char *file, t_map *map)
{
	int lines = count_lines(file);
	if (lines == 0)
		return (ft_error("Map is empty!"));
	else if (lines < 0)
		reutrn(ft_error("Failed to open or read file"));

	map->grid = read_map(file, lines);
	if (!map->grid)
		return (ft_error("Failed to read map"));

	map->height = lines;
	map->width = ft_strlen(map->grid[0]);

	validate_map(map);
	return (1);
}