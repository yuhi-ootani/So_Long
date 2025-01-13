/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:27:05 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/13 14:51:20 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }			t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int	main(void)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	t_data img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

// #include "mlx.h"
// #include <stdio.h>
// #include <stdlib.h>

// // Define window dimensions
// #define WINDOW_WIDTH 800
// #define WINDOW_HEIGHT 600

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	int		width;
// 	int		height;
// }			t_data;

// // Function to set a pixel in the image
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
// 		return ; // Prevent writing outside the image bounds
// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// // Rendering function to display the image
// int	render(t_data *data, void *mlx, void *win)
// {
// 	mlx_put_image_to_window(mlx, win, data->img, 0, 0);
// 	return (0);
// }

// // Key press handler to allow exiting the program
// int	handle_keypress(int key, void *param)
// {
// 	(void)param;
// 	if (key == 65307) // ESC key on X11
// 		exit(0);
// 	return (0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	int x, y;
// 	// Initialize MLX
// 	mlx = mlx_init();
// 	if (!mlx)
// 	{
// 		fprintf(stderr, "Failed to initialize MLX.\n");
// 		return (1);
// 	}
// 	// Create a new window
// 	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World!");
// 	if (!mlx_win)
// 	{
// 		fprintf(stderr, "Failed to create window.\n");
// 		return (1);
// 	}
// 	// Create a new image
// 	img.width = WINDOW_WIDTH;
// 	img.height = WINDOW_HEIGHT;
// 	img.img = mlx_new_image(mlx, img.width, img.height);
// 	if (!img.img)
// 	{
// 		fprintf(stderr, "Failed to create image.\n");
// 		return (1);
// 	}
// 	// Get image data address
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);
// 	if (!img.addr)
// 	{
// 		fprintf(stderr, "Failed to get image data address.\n");
// 		return (1);
// 	}
// 	// Fill the image with a gradient or a solid color for visibility
// 	for (y = 0; y < img.height; y++)
// 	{
// 		for (x = 0; x < img.width; x++)
// 		{
// 			// Example: Gradient from black to red
// 			int color = 0x000000FF; // Vary red component
// 			my_mlx_pixel_put(&img, x, y, color);
// 		}
// 	}
// 	// Alternatively, to set a single pixel, uncomment the following line:
// 	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); // Red pixel at (5,5)
// 	// Set up the render hook to display the image
// 	render(&img, mlx, mlx_win);
// 	// Optionally, set up an expose hook if your MLX version requires it
// 	// mlx_expose_hook(mlx_win, (int (*)(void*))render, &img);
// 	// Handle keypress events to allow exiting
// 	mlx_key_hook(mlx_win, handle_keypress, NULL);
// 	// Enter the MLX main loop
// 	mlx_loop(mlx);
// 	return (0);
// }
