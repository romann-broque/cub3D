/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_unique.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:58:10 by rbroque           #+#    #+#             */
/*   Updated: 2023/10/09 21:18:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

void	is_map_unique__test(void)
{
	// FAILURE TESTS //

	const char		not_unique1[] = "./tests/assets/wrong/not_unique1.cub";
	const char		not_unique2[] = "./tests/assets/wrong/not_unique2.cub";
	const char		not_unique3[] = "./tests/assets/wrong/not_unique3.cub";
	const char		not_unique4[] = "./tests/assets/wrong/not_unique4.cub";
	const char		not_unique5[] = "./tests/assets/wrong/not_unique5.cub";
	t_map *const	not_unique_map1 = get_map_from_file(not_unique1);
	t_map *const	not_unique_map2 = get_map_from_file(not_unique2);
	t_map *const	not_unique_map3 = get_map_from_file(not_unique3);
	t_map *const	not_unique_map4 = get_map_from_file(not_unique4);
	t_map *const	not_unique_map5 = get_map_from_file(not_unique5);

	CU_ASSERT_FALSE(is_map_unique(not_unique_map1));
	CU_ASSERT_FALSE(is_map_unique(not_unique_map2));
	CU_ASSERT_FALSE(is_map_unique(not_unique_map3));
	CU_ASSERT_FALSE(is_map_unique(not_unique_map4));
	CU_ASSERT_FALSE(is_map_unique(not_unique_map5));

	free_map(not_unique_map1);
	free_map(not_unique_map2);
	free_map(not_unique_map3);
	free_map(not_unique_map4);
	free_map(not_unique_map5);

	// SUCCESS TESTS //
	
	const char		unique1[] = "./tests/assets/correct/unique1.cub";
	const char		unique2[] = "./tests/assets/correct/unique2.cub";
	const char		unique3[] = "./tests/assets/correct/unique3.cub";
	const char		unique4[] = "./tests/assets/correct/unique4.cub";
	const char		unique5[] = "./tests/assets/correct/unique5.cub";
	t_map *const	unique_map1 = get_map_from_file(unique1);
	t_map *const	unique_map2 = get_map_from_file(unique2);
	t_map *const	unique_map3 = get_map_from_file(unique3);
	t_map *const	unique_map4 = get_map_from_file(unique4);
	t_map *const	unique_map5 = get_map_from_file(unique5);

	CU_ASSERT_TRUE(is_map_unique(unique_map1));
	CU_ASSERT_TRUE(is_map_unique(unique_map2));
	CU_ASSERT_TRUE(is_map_unique(unique_map3));
	CU_ASSERT_TRUE(is_map_unique(unique_map4));
	CU_ASSERT_TRUE(is_map_unique(unique_map5));

	free_map(unique_map1);
	free_map(unique_map2);
	free_map(unique_map3);
	free_map(unique_map4);
	free_map(unique_map5);
}
