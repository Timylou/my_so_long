/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:09:50 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/09 18:09:51 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_pixel_clean(t_img *img, int x, int y, int color)
{
	char			*dst;
	int				pos;
	long int		size;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	size = img->size_line * img->height;
	pos = ((y * img->size_line) + (x * (img->bpp / 8)));
	if (pos < 0)
		pos += size;
	if (pos > size)
		pos = pos % size;
	dst = img->data + pos;
	*(unsigned int *)dst = color;
}

void	ft_put_image_clean(t_img *img, int x_off, int y_off, t_img *buff)
{
	int	x;
	int	y;
	int	color;

	if (!buff || !img)
		return ;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = ft_get_pixel(img, x, y);
			if (color >= 0)
				ft_put_pixel_clean(buff, x + x_off, y + y_off, color);
			x++;
		}
		y++;
	}
}
