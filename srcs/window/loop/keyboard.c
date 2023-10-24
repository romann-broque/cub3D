/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:02:28 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 23:38:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	browse_mapping(t_win *window)
{
	const t_event_mapping	*mapping = get_mapping();
	int						ret_val;
	size_t					i;

	ret_val = EXIT_SUCCESS;
	i = 0;
	while (mapping[i].event != NULL && ret_val == EXIT_SUCCESS)
	{
		if (window->key_pressure[i] == true)
		{
			ret_val = mapping[i].event(window);
			refresh(window);
		}
		++i;
	}
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
