/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:20:59 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/03 22:21:01 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_frame(t_game *game)
{
	t_img	*cur_bg;
	int		i;

	i = 0;
	while (i < 5)
	{
		cur_bg = game->backgrounds[i];
		ft_put_image(cur_bg, cur_bg->x, cur_bg->y, game->frame);
		i++;
	}
}
