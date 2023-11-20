/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:39:28 by aikram            #+#    #+#             */
/*   Updated: 2023/11/20 21:05:05 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

int	handle_keypress(int keysym, t_able *table)
{
	if (keysym == 0)
		table->keys[0] = true;
	else if (keysym == 1)
		table->keys[1] = true;
	else if (keysym == 2)
		table->keys[2] = true;
	else if (keysym == 13)
		table->keys[3] = true;
	else if (keysym == 123)
		table->keys[4] = true;
	else if (keysym == 124)
		table->keys[5] = true;
	return (0);
}

int	handle_keyrelease(int keysym, t_able *table)
{
	if (keysym == 0)
		table->keys[0] = false;
	else if (keysym == 1)
		table->keys[1] = false;
	else if (keysym == 2)
		table->keys[2] = false;
	else if (keysym == 13)
		table->keys[3] = false;
	else if (keysym == 123)
		table->keys[4] = false;
	else if (keysym == 124)
		table->keys[5] = false;
	else if (keysym == 53)
		exit (ultimate_destroyer(table));
	return (0);
}

int	main_loop(t_able *table)
{
	handle_movements(table);
	calc(table);
	mlx_put_image_to_window(table->mlx.mlx, table->mlx.win, \
	table->mlx.img->img, 0, 0);
	return (0);
}
