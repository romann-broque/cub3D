/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_content_valid.test.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:17:08 by jess              #+#    #+#             */
/*   Updated: 2023/10/11 06:46:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cunit.test.h"

void	is_map_content_valid__test(void)
{
	// FAILURE TESTS //

	const char		bad_content1[] = "./tests/assets/wrong/bad_content1.cub";
	const char		bad_content2[] = "./tests/assets/wrong/bad_content2.cub";
	const char		bad_content3[] = "./tests/assets/wrong/bad_content3.cub";
	const char		bad_content4[] = "./tests/assets/wrong/bad_content4.cub";
	const char		bad_content5[] = "./tests/assets/wrong/bad_content5.cub";
	const char		bad_content6[] = "./tests/assets/wrong/bad_content6.cub";
	const char		bad_content7[] = "./tests/assets/wrong/bad_content7.cub";
	const char		bad_content8[] = "./tests/assets/wrong/bad_content8.cub";
	const char		bad_content9[] = "./tests/assets/wrong/bad_content9.cub";
	const char		bad_content10[] = "./tests/assets/wrong/bad_content10.cub";
	const char		bad_content11[] = "./tests/assets/wrong/bad_content11.cub";
	t_map *const	bad_content_map1 = get_map_from_file(bad_content1);
	t_map *const	bad_content_map2 = get_map_from_file(bad_content2);
	t_map *const	bad_content_map3 = get_map_from_file(bad_content3);
	t_map *const	bad_content_map4 = get_map_from_file(bad_content4);
	t_map *const	bad_content_map5 = get_map_from_file(bad_content5);
	t_map *const	bad_content_map6 = get_map_from_file(bad_content6);
	t_map *const	bad_content_map7 = get_map_from_file(bad_content7);
	t_map *const	bad_content_map8 = get_map_from_file(bad_content8);
	t_map *const	bad_content_map9 = get_map_from_file(bad_content9);
	t_map *const	bad_content_map10 = get_map_from_file(bad_content10);
	t_map *const	bad_content_map11 = get_map_from_file(bad_content11);

	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map1));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map2));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map3));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map4));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map5));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map6));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map7));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map8));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map9));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map10));
	CU_ASSERT_FALSE(is_map_content_valid(bad_content_map11));

	free_map(bad_content_map1);
	free_map(bad_content_map2);
	free_map(bad_content_map3);
	free_map(bad_content_map4);
	free_map(bad_content_map5);
	free_map(bad_content_map6);
	free_map(bad_content_map7);
	free_map(bad_content_map8);
	free_map(bad_content_map9);
	free_map(bad_content_map10);
	free_map(bad_content_map11);

	// SUCCESS TESTS //

	const char		good_content1[] = "./tests/assets/correct/good_content1.cub";
	const char		good_content2[] = "./tests/assets/correct/good_content2.cub";
	const char		good_content3[] = "./tests/assets/correct/good_content3.cub";
	const char		good_content4[] = "./tests/assets/correct/good_content4.cub";
	const char		good_content5[] = "./tests/assets/correct/good_content5.cub";
	t_map *const	good_content_map1 = get_map_from_file(good_content1);
	t_map *const	good_content_map2 = get_map_from_file(good_content2);
	t_map *const	good_content_map3 = get_map_from_file(good_content3);
	t_map *const	good_content_map4 = get_map_from_file(good_content4);
	t_map *const	good_content_map5 = get_map_from_file(good_content5);

	CU_ASSERT_TRUE(is_map_content_valid(good_content_map1));
	CU_ASSERT_TRUE(is_map_content_valid(good_content_map2));
	CU_ASSERT_TRUE(is_map_content_valid(good_content_map3));
	CU_ASSERT_TRUE(is_map_content_valid(good_content_map4));
	CU_ASSERT_TRUE(is_map_content_valid(good_content_map5));

	free_map(good_content_map1);
	free_map(good_content_map2);
	free_map(good_content_map3);
	free_map(good_content_map4);
	free_map(good_content_map5);
}
