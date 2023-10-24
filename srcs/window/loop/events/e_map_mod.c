/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_map_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:12:55 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/24 15:44:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_mod(t_win *const ptr)
{
	if (ptr->mod == E_STD)
		ptr->mod = E_MAP;
	else
		ptr->mod = E_STD;
	return (EXIT_SUCCESS);
}
