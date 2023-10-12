/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:50:14 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/12 20:17:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	start_map(char *const *const content)
{
	t_map *const	map = init_map(content);
	int				ret_val;

	ret_val = EXIT_FAILURE;
	if (map != NULL)
	{
		if (is_map_valid(map))
			ret_val = EXIT_SUCCESS;
		if (PRINT_DEBUG)
			print_map(map);
	}
	free_map(map);
	return (ret_val);
}

static int	start_game(const char *const filename)
{
	char **const	content = get_file(filename);
	int				ret_val;
	t_config		config;
	ssize_t			config_offset;

	if (content == NULL)
		return (EXIT_FAILURE);
	ret_val = EXIT_FAILURE;
	init_config(&config);
	config_offset = build_config(&config, content);
	if (config_offset != INVALID_OFFSET)
	{
		print_config(&config);
		ret_val = start_map(content + config_offset);
	}	
	free_config(&config);
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
