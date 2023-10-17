/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_close_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:50:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/15 14:55:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_win *const ptr)
{
	mlx_loop_end(ptr->mlx_ptr);
	return (EXIT_SUCCESS);
}
