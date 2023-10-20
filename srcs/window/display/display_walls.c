/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:43 by jess              #+#    #+#             */
/*   Updated: 2023/10/20 17:24:30 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_wall	*init_wall(
	t_wall **wall,
	const ssize_t lineheight,
	const ssize_t height
	)
{
	ssize_t		tmp1;
	ssize_t		tmp2;

	tmp1 = (lineheight * -1) / 2;
	printf("tmp1 = %zu\n", tmp1);
	tmp2 = height / 2;
	printf("tmp2 = %zu\n", tmp2);
	printf("Entrée dans init wall\n");
	// (*wall)->start = (lineheight * NEGATIVE * HALF) + (height * HALF);
	(*wall)->start = tmp1 + tmp2;
	printf("Apres calcul wall start\n");
	if ((*wall)->start < 0)
		(*wall)->start = 0;
	printf("Apres if wall start < 0\n");
	tmp1 = lineheight / 2;
	tmp2 = height / 2;
	// (*wall)->end = (lineheight * HALF) + (height * HALF);
	(*wall)->end = tmp1 + tmp2;
	printf("Apres calcul wall end\n");
	if ((*wall)->end >= height)
		(*wall)->end = height - 1;
	printf("Sortie dans init wall\n");
	return (*wall);
}

void	display_walls(
	t_win *const window,
	const ssize_t lineheight,
	const ssize_t height,
	const ssize_t x
	)
{
	ssize_t	i;
	t_wall	*wall;

	wall = init_wall(&wall, lineheight, height);
	i = 0;
	while(i < (wall->end - wall->start))
	{
		put_pixel(&(window->data), x, wall->start + i, BLUE);
		i++;
	}
}
