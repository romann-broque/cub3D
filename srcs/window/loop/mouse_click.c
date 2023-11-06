/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:35:41 by lechon            #+#    #+#             */
/*   Updated: 2023/11/06 15:04:34 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_click(
	const int click,
	__attribute__((unused))int x,
	__attribute__((unused))int y,
	t_win *const window
)
{
	if (click == 1 && window != NULL)
	{
		if (window->is_mouse_in_window == true)
			window->is_mouse_in_window = false;
		else
			window->is_mouse_in_window = true;
	}
	return (EXIT_SUCCESS);
}
