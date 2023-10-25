/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:38:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 07:33:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

ssize_t	find_event_index(
	const t_event_mapping *const mapping,
	const int key
	)
{
	ssize_t	i;

	i = 0;
	while (mapping[i].event != NULL)
	{
		if (key == mapping[i].key.key_value)
			return (i);
		++i;
	}
	return (-1);
}

ssize_t	find_key_index(
	const t_key *keys,
	const int key
	)
{
	ssize_t	i;

	i = 0;
	while (i < KEY_COUNT)
	{
		if (key == keys[i].key_value)
			return (i);
		++i;
	}
	return (-1);
}

bool	is_same_key_in(const t_key *const keys, const t_key key)
{
	const ssize_t	index = find_key_index(keys, key.key_value);

	return (index != -1 && keys[index].pressure == key.pressure);
}

void	set_key_status(
	t_win *const window,
	const int key,
	const bool is_pressed
	)
{
	const ssize_t	index = find_key_index(window->keys, key);

	if (index != -1)
		window->keys[index].pressure = is_pressed;
}

t_event_mapping	*get_mapping(void)
{
	static t_event_mapping	mapping[] = {
	{.key = {.key_value = K_LEFT, .pressure = true}, .event = rotate_left},
	{.key = {.key_value = K_RIGHT, .pressure = true}, .event = rotate_right},
	{.key = {.key_value = K_W, .pressure = true}, .event = move_forward},
	{.key = {.key_value = K_S, .pressure = true}, .event = move_backward},
	{.key = {.key_value = K_A, .pressure = true}, .event = move_left},
	{.key = {.key_value = K_D, .pressure = true}, .event = move_right},
	{.key = {.key_value = K_M, .pressure = true}, .event = enable_map_mod},
	{.key = {.key_value = K_M, .pressure = false}, .event = disable_map_mod},
	{.key = {.key_value = K_ESC, .pressure = true}, .event = close_window},
	{.key = {.key_value = NO_KEY}, .event = NULL},
	};

	return (mapping);
}
