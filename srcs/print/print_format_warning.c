/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_warning.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:21:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/11/01 18:28:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_format_warning(const char *const warning_message)
{
	print_error(ORANGE_PRINT"Warning\n%s\n"NC, warning_message);
}
