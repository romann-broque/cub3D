/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jess <jess@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/11 16:04:00 by jess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_game(const char *const filename)
{
	char **const	content = get_file(filename);
	int				ret_val;
	t_map			*map;
	t_config		*config;

	if (content == NULL)
		return (EXIT_FAILURE);
	ret_val = EXIT_FAILURE;
	config = init_config(content);
	if (config != NULL)
	{
		map = init_map(content);
		if (map != NULL)
		{
			if (is_map_valid(map))
				ret_val = EXIT_SUCCESS;
			if (PRINT_DEBUG)
				print_map(map);
		}
	}
	free_config(config);
	free_map(map);
	free_strs(content);
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
