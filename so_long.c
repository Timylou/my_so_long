/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:04:07 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/25 14:34:58 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		write(1, "Error\nYou must have 1 map !\n", 28);
		return (EXIT_FAILURE);
	}
	game = ft_init_game(argv);
	if (!game)
		return (EXIT_FAILURE);
	mlx_destroy_window(game->mlx, game->win);
	game->width = game->map->width * 64;
	game->height = game->map->height * 64;
	game->win = mlx_new_window(game->mlx, game->width, game->height, "Miaou");
	ft_map_to_buffer(game);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer->img, 0, 0);
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win, DestroyNotify, 0, mlx_loop_end, game->mlx);
	mlx_loop(game->mlx);
	ft_mini_free(game);
	return (EXIT_SUCCESS);
}
