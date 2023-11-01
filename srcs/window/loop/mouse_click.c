/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lechon <lechon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:35:41 by lechon            #+#    #+#             */
/*   Updated: 2023/11/01 12:21:05 by lechon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// segfault ici a l'incrementation

int	mouse_click(const int click, t_win *const window)
{
	if (click == 1)
		window->keys->mouse_clicks++;
	return (EXIT_SUCCESS);
}
