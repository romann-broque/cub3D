/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_map_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:12:55 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/25 07:37:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	enable_map_mod(t_win *const ptr)
{
	ptr->mod = E_MAP;
	return (EXIT_SUCCESS);
}

int	disable_map_mod(t_win *const ptr)
{
	ptr->mod = E_STD;
	return (EXIT_SUCCESS);
}
