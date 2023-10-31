/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:02:28 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/31 11:39:38 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	browse_mapping(t_win *window)
{
	const t_event_mapping	*mapping = get_key_mapping();
	int						ret_val;
	size_t					i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (mapping[i].event != NULL && ret_val == EXIT_SUCCESS)
	{
		if (is_same_key_in(window->keys, mapping[i].key) == true)
			ret_val = mapping[i].event(window);
		++i;
	}
	if (ret_val == EXIT_SUCCESS)
		return (refresh(window));
	return (ret_val);
}

int	key_press(const int key, t_win *window)
{
	set_key_status(window, key, true);
	return (EXIT_SUCCESS);
}

int	key_release(const int key, t_win *window)
{
	set_key_status(window, key, false);
	return (EXIT_SUCCESS);
}
