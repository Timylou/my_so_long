/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:39:04 by yel-mens          #+#    #+#             */
/*   Updated: 2025/02/19 14:39:04 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static void ft_putnbr(int nbr)
{
    if (nbr < 10)
    {
        ft_putchar('0' + nbr);
        return ;
    }
    ft_putnbr(nbr / 10);
    ft_putnbr(nbr % 10);
}

void    ft_print_steps(int steps)
{
    write(1, "step : ", 7);
    ft_putnbr(steps);
    write(1, "\n", 1);
}