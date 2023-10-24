/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:38:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 23:39:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static ssize_t	find_event_index(
	const t_event_mapping *const mapping,
	const int key
	)
{
	ssize_t	i;

	i = 0;
	while (mapping[i].event != NULL)
	{
		if (key == mapping[i].key)
			return (i);
		++i;
	}
	return (-1);
}

void	set_key_status(
	t_win *const window,
	const int key,
	const bool is_pressed
	)
{
	const t_event_mapping	*mapping = get_mapping();
	const ssize_t			index = find_event_index(mapping, key);

	if (index != -1)
		window->key_pressure[index] = is_pressed;
}

t_event_mapping	*get_mapping(void)
{
	static t_event_mapping	mapping[] = {
	{.key = K_LEFT, .event = rotate_left},
	{.key = K_RIGHT, .event = rotate_right},
	{.key = K_W, .event = move_forward},
	{.key = K_S, .event = move_backward},
	{.key = K_A, .event = move_left},
	{.key = K_D, .event = move_right},
	{.key = K_M, .event = map_mod},
	{.key = K_ESC, .event = close_window},
	{.key = NO_KEY, .event = NULL},
	};

	return (mapping);
}
