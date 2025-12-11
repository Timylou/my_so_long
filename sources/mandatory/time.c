/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:57:04 by yel-mens          #+#    #+#             */
/*   Updated: 2025/12/09 19:57:05 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

float	get_delta_time(void)
{
	static long last = 0;
	long now = get_time_ms();
	float dt;

	if (last == 0)
	{
		last = now;
		return 0.0f;
	}
	dt = (now - last) / 1000.0f;
	last = now;
	return (dt);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec * 1000L + tv.tv_usec / 1000));
}
