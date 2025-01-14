/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:43:22 by yel-mens          #+#    #+#             */
/*   Updated: 2025/01/14 15:40:54 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_game	*game;
	int		i;

	game = ft_init_game();
	if (!game)
		return (EXIT_FAILURE);

	ft_put_image(game->backgrounds[0], 0, 0, game->buffer);
	ft_put_image(game->backgrounds[1], 0, 80, game->buffer);
	ft_put_image(game->backgrounds[2], 0, 328, game->buffer);
	ft_put_image(game->backgrounds[3], 0, 340, game->buffer);
	ft_put_image(game->backgrounds[4], 0, 340, game->buffer);
	mlx_put_image_to_window(game->mlx, game->win, game->buffer->img, 0, 0);

	mlx_hook(game->win, KeyPress, KeyPressMask,ft_handle_input, game);
	mlx_loop(game->mlx);
	ft_mini_free(game);
	return (EXIT_SUCCESS);
}
