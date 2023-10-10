/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/10 07:14:36 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_game(const char *const filename)
{
	int			ret_val;
	char *const	content = get_file(filename);
	t_map		*map;

	if (content == NULL)
		return (EXIT_FAILURE);
	ret_val = EXIT_FAILURE;
	map = init_map(content);
	if (map != NULL)
	{
		if (is_map_valid(map))
			ret_val = EXIT_SUCCESS;
		if (PRINT_DEBUG)
			print_map(map);
	}
	free_map(map);
	free(content);
	return (ret_val);
}

int	main(int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac == EXPECTED_ARG_COUNT)
		ret_val = start_game(av[1]);
	return (ret_val);
}
