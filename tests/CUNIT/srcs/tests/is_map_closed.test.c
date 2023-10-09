/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 00:48:53 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 12:56:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

static t_map	*get_map_from_file(const char *const filename)
{
	char *const	content = get_file(filename);
	t_map		*map;

	if (content == NULL)
		return (NULL);
	map = init_map(content);
	free(content);
	return (map);
}

void	is_map_closed__test(void)
{

	// FAILURE TESTS //

	const char		open1[] = "./tests/assets/wrong/open1.cub";
	const char		open2[] = "./tests/assets/wrong/open2.cub";
	const char		open3[] = "./tests/assets/wrong/open3.cub";
	const char		open4[] = "./tests/assets/wrong/open4.cub";
	const char		open5[] = "./tests/assets/wrong/open5.cub";
	const char		open6[] = "./tests/assets/wrong/open6.cub";
	const char		open7[] = "./tests/assets/wrong/open7.cub";
	const char		open8[] = "./tests/assets/wrong/open8.cub";
	const char		open9[] = "./tests/assets/wrong/open9.cub";
	const char		open10[] = "./tests/assets/wrong/open10.cub";
	t_map *const	open_map1 = get_map_from_file(open1);
	t_map *const	open_map2 = get_map_from_file(open2);
	t_map *const	open_map3 = get_map_from_file(open3);
	t_map *const	open_map4 = get_map_from_file(open4);
	t_map *const	open_map5 = get_map_from_file(open5);
	t_map *const	open_map6 = get_map_from_file(open6);
	t_map *const	open_map7 = get_map_from_file(open7);
	t_map *const	open_map8 = get_map_from_file(open8);
	t_map *const	open_map9 = get_map_from_file(open9);
	t_map *const	open_map10 = get_map_from_file(open10);

	CU_ASSERT_FALSE(is_map_closed(open_map1));
	CU_ASSERT_FALSE(is_map_closed(open_map2));
	CU_ASSERT_FALSE(is_map_closed(open_map3));
	CU_ASSERT_FALSE(is_map_closed(open_map4));
	CU_ASSERT_FALSE(is_map_closed(open_map5));
	CU_ASSERT_FALSE(is_map_closed(open_map6));
	CU_ASSERT_FALSE(is_map_closed(open_map7));
	CU_ASSERT_FALSE(is_map_closed(open_map8));
	CU_ASSERT_FALSE(is_map_closed(open_map9));
	CU_ASSERT_FALSE(is_map_closed(open_map10));

	free_map(open_map1);
	free_map(open_map2);
	free_map(open_map3);
	free_map(open_map4);
	free_map(open_map5);
	free_map(open_map6);
	free_map(open_map7);
	free_map(open_map8);
	free_map(open_map9);
	free_map(open_map10);

	// SUCCESS TESTS //
	
	const char		closed1[] = "./tests/assets/correct/closed1.cub";
	const char		closed2[] = "./tests/assets/correct/closed2.cub";
	const char		closed3[] = "./tests/assets/correct/closed3.cub";
	const char		closed4[] = "./tests/assets/correct/closed4.cub";
	const char		closed5[] = "./tests/assets/correct/closed5.cub";
	const char		closed6[] = "./tests/assets/correct/closed6.cub";
	const char		closed7[] = "./tests/assets/correct/closed7.cub";
	const char		closed8[] = "./tests/assets/correct/closed8.cub";
	const char		closed9[] = "./tests/assets/correct/closed9.cub";
	const char		closed10[] = "./tests/assets/correct/closed10.cub";
	t_map *const	closed_map1 = get_map_from_file(closed1);
	t_map *const	closed_map2 = get_map_from_file(closed2);
	t_map *const	closed_map3 = get_map_from_file(closed3);
	t_map *const	closed_map4 = get_map_from_file(closed4);
	t_map *const	closed_map5 = get_map_from_file(closed5);
	t_map *const	closed_map6 = get_map_from_file(closed6);
	t_map *const	closed_map7 = get_map_from_file(closed7);
	t_map *const	closed_map8 = get_map_from_file(closed8);
	t_map *const	closed_map9 = get_map_from_file(closed9);
	t_map *const	closed_map10 = get_map_from_file(closed10);

	CU_ASSERT_TRUE(is_map_closed(closed_map1));
	CU_ASSERT_TRUE(is_map_closed(closed_map2));
	CU_ASSERT_TRUE(is_map_closed(closed_map3));
	CU_ASSERT_TRUE(is_map_closed(closed_map4));
	CU_ASSERT_TRUE(is_map_closed(closed_map5));
	CU_ASSERT_TRUE(is_map_closed(closed_map6));
	CU_ASSERT_TRUE(is_map_closed(closed_map7));
	CU_ASSERT_TRUE(is_map_closed(closed_map8));
	CU_ASSERT_TRUE(is_map_closed(closed_map9));
	CU_ASSERT_TRUE(is_map_closed(closed_map10));

	free_map(closed_map1);
	free_map(closed_map2);
	free_map(closed_map3);
	free_map(closed_map4);
	free_map(closed_map5);
	free_map(closed_map6);
	free_map(closed_map7);
	free_map(closed_map8);
	free_map(closed_map9);
	free_map(closed_map10);
}
