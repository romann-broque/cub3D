/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/05 15:57:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

//////////////
// INCLUDES //
//////////////

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/////////////
// DEFINES //
/////////////

# define EXPECTED_ARG_COUNT	2
# define INVALID_FD			-1

//// read_map ////

// get_file.c

char	*get_file(const char *const file_name);

#endif