/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:32:51 by aikram            #+#    #+#             */
/*   Updated: 2023/11/23 23:25:57 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub69d.h"
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>

// bool	print_and_return(const char *msg)
// {
// 	write(STDERR_FILENO, msg, strlen(msg));
// 	return (false);
// }


bool	loop_chk(size_t len, size_t idx, char *map)
{
	size_t counter;

	counter = 0;
	while ((map[idx] == ' ' || map[idx] == '1' || !map[idx]) && counter < len)
	{
		counter++;
		idx++;
	}
	if (counter < len)
		return (false);
	return (true);
}

bool	chk_updown(size_t idx, char *map)
{
	if (!idx)
	{
		if (!loop_chk(2, idx, map))
			return (false);
	}
	else if (!map[idx + 1])
	{
		if (!loop_chk(2, idx - 1, map))
			return (false);
	}
	else
		if (!loop_chk(3, idx - 1, map))
			return (false);
	return (true);
}

bool	hole_detective(char **map, size_t x, size_t y, short l)
{
	while (map[y][x])
	{
		// if (y == 2)
		// 	printf("map[%zu][%zu] == %c\n", y, x, map[y][x]);
		if (!y && map[y + 1] && map[y][x] == ' ')
		{
			// printf("y line = %zu\n", y);
			// printf("x line = %zu\n", x);
			if (!chk_updown(x, map[y]) \
			|| !chk_updown(x, map[y + 1])) {
				printf("ohhh myyy fuiyo\n");
				return (true);
			}
		}
		else if (!map[y + 1] && map[y][x] == ' ')
		{
			printf("b\n");
			if (!chk_updown(x, map[y - 1]) \
			|| !chk_updown(x, map[y])) {
				printf("ohhh myyy fuiyoo \n");
				return (true);
			}
		}
		else if (map[y][x] == ' ')
		{
			printf("c\n");
			l = -1;
			while (chk_updown(x, map[y + l]) && l < 2)
				l++;
			if (l != 2) {
				printf("ohhh myyy fuiyooo  \n");
				return (true);
			}
		}
		x++;
	}
	return (false);
}

int	chk_sneaky_space(char **map)
{
	size_t	i[2];

	ft_memset(i, 0, sizeof(size_t) * 2);
	while (map[i[0]])
	{
		printf("%s\n", map[i[0]]);
		if (hole_detective(map, i[1], i[0], -1))
			return (!print_and_return("BH"));
		i[0]++;
	}
	return (0);
}

// int main() {
// 	char *m[] = {
// 		"111111111111",
// 		"100000000011",
// 		"100000000001",
// 		"100000000001",
// 		"10S000000001",
// 		"111111111111",
// 		"110000000001",
// 		"111111111111",
// 		NULL
// 	};
// 	chk_sneaky_space(m);
// 	return (0);
// }

// 		// "111111111111",
// 		// "100000000011",
// 		// "10000000001",
// 		// "100000000001",
// 		// "10S000000001",
// 		// "111111111111",
// 		// "110000000001",
// 		// "111111111111",