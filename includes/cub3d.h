/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/05 14:25:54 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>

/* READ MAP ACCESS */
bool	read_map_access(const char *const filename);

#endif