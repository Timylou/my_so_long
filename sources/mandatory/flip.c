/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:42:49 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/09 18:42:50 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_copy_image(t_img	*flip, t_img *src, int src_pos, int dst_pos)
{
	int	i;
	int	bpp;

	bpp = flip->bpp / 8;
	i = 0;
	while (i < bpp)
	{
		flip->data[dst_pos + i] = src->data[src_pos + i];
		i++;
	}
}

static void	ft_flip(t_img *flip, t_img *src)
{
	int		y;
	int		x;
	int		src_pos;
	int		dst_pos;
	int		bpp;

	bpp = flip->bpp / 8;
	y = 0;
	while (y < flip->height)
	{
		x = 0;
		while (x < flip->width)
		{
			src_pos = (y * flip->size_line) + (x * bpp);
			dst_pos = (y * flip->size_line) + ((flip->width - 1 - x) * bpp);
			ft_copy_image(flip, src, src_pos, dst_pos);
			x++;
		}
		y++;
	}
}

void	*flip_xpm_horizontally(t_img *src, t_game *game)
{
	t_img	*flip;

	flip = malloc(sizeof(t_img));
	if (!flip)
		ft_error("flip malloc error\n", game);
	flip->img = mlx_new_image(game->mlx, src->width, src->height);
	flip->data = mlx_get_data_addr(flip->img, &flip->bpp,
			&flip->size_line, &flip->edn);
	flip->width = src->width;
	flip->height = src->height;
	flip->x = src->x;
	flip->y = src->y;
	ft_flip(flip, src);
	return (flip);
}
