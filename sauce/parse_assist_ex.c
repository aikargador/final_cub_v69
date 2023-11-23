/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assist_ex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:30:48 by aikram            #+#    #+#             */
/*   Updated: 2023/11/23 23:39:53 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"

int	padder_pooper(char **map)
{
	unsigned long long	man;
	size_t				i[3];
	char				**pad;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (map[i[0]])
	{
		if (ft_strlen(map[i[0]] > i[1]))
			i[1] = ft_strlen(map[i[0]]);
		i[0]++;
	}
	pad = ft_calloc(i[0] * sizeof(char *));
	if (!pad)
		return 1;//make exit layter
	while (i[2] < i[0])
	{
		pad[i[2]] = ft_calloc(i[1] * sizeof(char));
		if (!pad[i[2]])
			return 1;//return eggor later
	//copy string to the padd string including or followed by spaces!
	}
}
