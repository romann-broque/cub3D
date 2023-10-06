/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/06 15:00:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_game(const char *const filename)
{
	char *const	content = get_file(filename);
	t_map		*map;

	if (content == NULL)
		return (EXIT_FAILURE);
	map = init_map(content);
	print_map(map);
	free_map(map);
	free(content);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECTED_ARG_COUNT)
		ret_val = start_game(av[1]);
	return (ret_val);
}
