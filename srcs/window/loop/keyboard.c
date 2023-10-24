/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:02:28 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 08:30:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	browse_mapping(
	t_event_mapping *mapping,
	const int key,
	t_win *window)
{
	int		ret_val;
	size_t	i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (mapping[i].event != NULL)
	{
		if (key == mapping[i].key)
			ret_val = mapping[i].event(window);
		++i;
	}
	refresh(window);
	return (ret_val);
}

int	key_press(const int key, t_win *window)
{
	static t_event_mapping	mapping[] = {
	{.key = K_W, .event = move_forward},
	{.key = K_S, .event = move_backward},
	{.key = K_ESC, .event = close_window},
	{.key = NO_KEY, .event = NULL},
	};

	return (browse_mapping(mapping, key, window));
}
