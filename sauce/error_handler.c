/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:24:22 by aikram            #+#    #+#             */
/*   Updated: 2023/11/20 21:04:06 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

bool	print_and_return(const char *mono_sodium_glutamate)
{
	write(STDERR_FILENO, mono_sodium_glutamate, \
	ft_strlen(mono_sodium_glutamate));
	return (false);
}

bool	free_table(t_able *table)
{
	int	i;

	i = -1;
	if (table->mlx.win)
		mlx_destroy_window(table->mlx.mlx, table->mlx.win);
	if (table->mlx.img)
		free(table->mlx.img);
	if (table->mlx.mlx)
		free(table->mlx.mlx);
	while (++i < 4 && table->swen_tx)
		free(table->swen_tx[i]);
	if (table->swen_tx)
		free(table->swen_tx);
	return (69);
}

int	ultimate_destroyer(t_able *table)
{
	free_table(table);
	free_parser(table->parse);
	return (0);
}
